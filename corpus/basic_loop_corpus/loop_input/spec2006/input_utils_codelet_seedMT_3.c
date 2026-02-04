#include <stdio.h>
#include <inttypes.h>

int left;
unsigned int x;
unsigned int *s;
int j;

static unsigned int s_buffer[624];
static int s_initialized = 0;

void init_vars() {
    if (!s_initialized) {
        x = 12345U;
        s = s_buffer;
        s_initialized = 1;
    }
}