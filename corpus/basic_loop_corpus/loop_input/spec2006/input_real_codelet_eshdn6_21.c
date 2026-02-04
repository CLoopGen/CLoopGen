#include <inttypes.h>

unsigned short *x;
int i;
unsigned short *p;

static unsigned short x_data[131072];
static unsigned short p_data[131072];

void init_vars() {
    x = &x_data[131071];
    p = &p_data[131071];
}