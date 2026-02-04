#include <stdint.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
size_t buf_len;
size_t i;

void init_vars() {
    buf_len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU
    buf = (unsigned char *)malloc(buf_len);
    if (!buf) {
        buf_len = 0;
        return;
    }
    memset(buf, 0, buf_len);
}