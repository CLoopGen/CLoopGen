#include <inttypes.h>

int i;
int top;
unsigned long *cdp;

static unsigned long cdp_buffer[32768]; // 32768 * 8 = 262144 bytes ~ 256KB

void init_vars() {
    i = 0;
    top = 32768;
    cdp = cdp_buffer;
}