// POSIX file handling using system calls in C++

#include<iostream>   // INPUT OUTPUT STREAM HEADER -> /usr/include/c++/<version>/iostream
#include<string>     // STRING HEADER -> /usr/include/c++/<version>/string
#include<unistd.h>   // UNIX STANDARD HEADER -> /usr/include/unistd.h (LINUX)
#include<fcntl.h>    // FILE CONTROL HEADER -> /usr/include/fcntl.h (LINUX)
#include<cstring>    // C STRING FUNCTIONS HEADER -> /usr/include/c++/<version>/cstring
#include<cerrno>     // ERROR REPORTING HEADER -> for 'errno' and strerror()

// Function to read and display contents of a file using POSIX system calls
void readFile(const char *filename) {
    // O_RDONLY -> open the file in read-only mode
    int fd = open(filename, O_RDONLY); // fd: file descriptor (a low-level handle to the file)

    // If open fails, 'open()' returns -1
    if(fd == -1) {
        std::cerr << "Error opening " << filename << ": " << strerror(errno) << std::endl;
        return;
    }

    char buffer[1000];       // Buffer to store file content while reading
    ssize_t bytes_read;      // ssize_t: signed size type, used for byte counts

    std::cout << "File contents:\n";

    // Read from file into buffer (up to sizeof(buffer) bytes at a time)
    // Loop continues until 'read' returns 0 (end of file) or -1 (error)
    while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        // 'write' writes data from buffer to STDOUT (console)
        if(write(STDOUT_FILENO, buffer, bytes_read) == -1) {
            std::cerr << "Write Error: " << strerror(errno) << std::endl;
            break;
        }
    }

    // If read failed (-1), print the error
    if(bytes_read == -1) {
        std::cerr << "Read Error: " << strerror(errno) << std::endl;
    }

    // Close the file after reading
    close(fd);
}

// Function to write content to a file using POSIX system calls
void writeFile(const char *filename, const char *content) {
    // O_WRONLY  -> open for writing
    // O_CREAT   -> create file if it doesn't exist
    // O_TRUNC   -> truncate file to zero length if it exists
    // 0644      -> permission bits: -rw-r--r-- (owner can read/write, others read)
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Check if file opened successfully
    if (fd == -1) {
        std::cerr << "Error opening " << filename << ": " << strerror(errno) << std::endl;
        return;
    }

    // Write content to the file
    // strlen(content) -> number of bytes to write
    ssize_t bytes_written = write(fd, content, strlen(content));

    // Check for write errors
    if (bytes_written == -1) {
        std::cerr << "Write error: " << strerror(errno) << std::endl;
    } else {
        std::cout << "Wrote " << bytes_written << " bytes to " << filename << std::endl;
    }

    // Close the file after writing
    close(fd);
}

int main() {
    const char *filename = "content.txt";  // Name of the file to write/read
    const char *content = "This is a sample content to write into the file."; // Sample content

    writeFile(filename, content);  // Write content to file
    readFile(filename);            // Read and display file content

    return 0;
}
