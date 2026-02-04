#include <inttypes.h>

unsigned long *r;
unsigned long *b;
int dl;
unsigned long c;
unsigned long t;

static unsigned long buffer_b[32768];
static unsigned long buffer_r[32768];

void init_vars() {
    for (int i = 0; i < 32768; ++i) {
        buffer_b[i] = (unsigned long)(i * 71 % 1000);
        buffer_r[i] = 0;
    }
    b = buffer_b;
    r = buffer_r;
    dl = -32768;
    c = 0;
    t = 0;
}