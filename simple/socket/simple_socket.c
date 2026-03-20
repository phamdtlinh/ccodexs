#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6667   // port IRC chuẩn
#define BUF_SIZE 512

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];
    
    // 1. Tạo socket (TCP)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // 2. Bind socket vào địa chỉ + port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; // lắng nghe tất cả interface
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(server_fd);
        exit(1);
    }

    // 3. Listen
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        close(server_fd);
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // 4. Chấp nhận client
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept");
        close(server_fd);
        exit(1);
    }

    printf("Client connected!\n");

    // 5. Nhận dữ liệu (đơn giản nhất)
    while (1) {
        ssize_t n = read(client_fd, buffer, BUF_SIZE - 1);
        if (n <= 0) break;
        buffer[n] = '\0';
        printf("Received: %s", buffer);

        // Nếu nhận PING, reply PONG
        if (strncmp(buffer, "PING", 4) == 0) {
            char pong[BUF_SIZE];
            snprintf(pong, sizeof(pong), "PONG%s\r\n", buffer + 4);
            write(client_fd, pong, strlen(pong));
            printf("Sent: %s", pong);
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}