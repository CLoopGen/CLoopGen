#include <stdint.h>
#include <stdlib.h>

unsigned short *x;
unsigned short bits;
int i;

static unsigned short *x_storage;
static int total_elements = 1 << 20; // ~2MB of data (1M elements * 2 bytes)

void init_vars() {
    x_storage = (unsigned short *)calloc(total_elements, sizeof(unsigned short));
    if (!x_storage) exit(1);

    for (int idx = 0; idx < total_elements; idx++) {
        x_storage[idx] = (unsigned short)(idx & 0xFFFF);
    }

    x = x_storage;
    bits = 0;
    i = 0;
}