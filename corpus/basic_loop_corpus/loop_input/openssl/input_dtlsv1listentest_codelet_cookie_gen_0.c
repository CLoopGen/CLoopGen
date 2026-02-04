#include <inttypes.h>

unsigned char *cookie;
unsigned int i;

static unsigned char cookie_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    cookie = cookie_buffer;
    i = 0;
}