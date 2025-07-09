#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/ip.h>
#include<cstring>
#include <arpa/inet.h> // provides functions for ip address manipulation and byte order conversion
// arpa - Advanced Research Project Agency

const int PORT = 9000;
const int BUFFER_SIZE = 1024;

int main() {
    // 1. Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    // 2.Bind server address and port with socket
    struct sockaddr_in address; // sockaddr_in - in referes to ipv4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); // here tcp/ip protocol uses big endian way of storing, so if conversion from le to be needed it will do that
    // htons - host to network short, short to convert 16 bit (port), long to convert 32 bit (ip address)

    // binds the ip + port or path to a socket fd
    if(bind(server_fd, (struct sockaddr*) &address, sizeof(sockaddr)) == -1) {
        std::cerr << "Bind failed\n";
        return -1;
    }

    // 3. Listen for connections
    // listen(sd, n) N connection requests will be queued before further requests are refused.
    if(listen(server_fd, 3) == -1) {
        std::cerr << "listen failed\n";
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    // 4. Accept a connection
    sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    // the accept also write the client info, thats why it is passed as reference
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if(client_fd == -1) {
        std::cerr << "Accept failed\n";
        return -1;
    }

    // internet network to presentation (converts binary ip to readable ip)
    char client_ip[INET_ADDRSTRLEN];
    // inet_ntop() expects a pointer to the IP address
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    std::cout << "Client Connected: " << client_ip << std::endl;

    // 5. Read client data
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        std::cerr << "Read failed\n";
    } else {
        std::cout << "Received: " << buffer << std::endl;
    }

    // Send Response
    const char* response = "Hello from server!";
    // there are several modes, 0 means no special modes
    send(client_fd, response, strlen(response), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}