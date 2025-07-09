#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<cstring>


const int PORT = 9000;
const char* SERVER_IP = "127.0.0.1";

int main() {
    // 1. create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    // 2. connect to server
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // presentation to network, returns 1 for succes, 0 for invalid address, -1 for error
    if(inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address\n";
        return -1;
    }

    // return 0 for success, -1 for failure
    if(connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed\n";
        return -1;
    }

    // 3. Send data
    const char* message = "Hey this is client";
    send(socket_fd, message, strlen(message), 0);
    std::cout << "Message Sent!\n";

    // 4. Read response
    char buffer[1024];
    ssize_t bytes_read = read(socket_fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        std::cerr << "Read failed\n";
    } else {
        std::cout << "Server Response: " << buffer << std::endl;
    }

    close(socket_fd);

    return 0;
}