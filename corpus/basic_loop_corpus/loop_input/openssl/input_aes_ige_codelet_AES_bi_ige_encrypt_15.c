#include <stdint.h>
#include <string.h>

unsigned char *out;
size_t n;
unsigned char *iv;

static unsigned char out_buf[1024 * 128]; // 128KB
static unsigned char iv_buf[16];

void init_vars() {
    out = out_buf;
    iv = iv_buf;
    n = 0;
    memset(out_buf, 0x5A, sizeof(out_buf));
    memset(iv_buf, 0xA5, sizeof(iv_buf));
}