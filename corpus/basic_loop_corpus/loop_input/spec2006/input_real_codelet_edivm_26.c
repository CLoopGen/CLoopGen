#include <inttypes.h>

int i;
unsigned short *p;

static unsigned short p_buffer[134217728]; // ~256MB to target 0.01s runtime

void init_vars() {
    i = 0;
    p = p_buffer;
}