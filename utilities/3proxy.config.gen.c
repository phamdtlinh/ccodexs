#include <stdio.h>
#include <stdlib.h>

/**
 * Tool: 3Proxy Config Generator (Sư phụ Edition)
 * Chức năng: Tự động hóa việc tạo 256 cụm bind socket chuẩn chỉ.
 */

int main() {
    FILE *f = fopen("3proxy.cfg", "w");
    if (!f) return 1;

    // Header mặc định
    fprintf(f, "daemon\nlog /dev/stdout\nlogformat \"L%%d-%%m-%%Y %%H:%%M:%%S %%U %%C:%%c %%R:%%r %%Q/%%E\"\nnserver 8.8.8.8\nnscache 65536\n\n");

    char base_ip[] = "10.255.254"; // Dải của Sư phụ
    int port = 1080;

    for (int i = 0; i <= 255; i++) {
        fprintf(f, "# --- User %d ---\n", i);
        fprintf(f, "auth strong\n");
        fprintf(f, "users user%d:CL:pass%d\n", i, i);
        fprintf(f, "allow user%d\n", i);
        fprintf(f, "parent 1000 tcp %s.%d 0\n", base_ip, i);
        fprintf(f, "external %s.%d\n", base_ip, i);
        fprintf(f, "socks -p%d -i %s.%d\n", port, base_ip, i);
        fprintf(f, "flush\n\n");
    }

    fclose(f);
    printf("Thơm rồi Sư phụ ơi! File 3proxy.cfg đã sẵn sàng.\n");
    return 0;
}