// sys is the folder contains system level headers maintained by os
#include<sys/socket.h> // contains structures needed for sockets
#include<sys/un.h> // UNIX header, defines sockaddr_un
#include<netinet/in.h> // network internet header / Internet Header, has structures for ip, socket stream, datagram socket

/*
    Syntax socket(address domain type, mode, socket type, 0);
        -> address domain - 2 types
            UNIX domain (AF_UNIX) - shares common file system communication, data does'nt go beyond kernel, has char string as address
            IP domain (AF_INET for IPv4, AF_INET6 for IPv6) - communication between two host on the internet, has IPv4 and IPv6 as address
        -> Socket types
            1. Socket Stream - uses TCP protocol
            2. Datagram Stream - uses UDP protocol
        -> Unix domain socket
            0 -> use the default protocol
*/

void unixDomain() {
    int socketfd = socket(AF_UNIX, SOCK_STREAM, 0); // returns file descriptor

    // sockaddr_un = socket_address_unix
    struct sockaddr_un socket_address = {AF_UNIX, "tmp/socket"};

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    bind(socketfd, (struct sockaddr*)&socket_address, sizeof(socket_address));
}

void ipDomain() {

    int socketfd = socket(AF_INET, SOCK_STREAM, 0); // returns file descriptor

    // sockaddr_un = socket_address_unix
    struct sockaddr_un socket_address = {AF_INET, "tmp/socket"};

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    bind(socketfd, (struct sockaddr*)&socket_address, sizeof(socket_address));
}

int main() {
    ipDomain();
}