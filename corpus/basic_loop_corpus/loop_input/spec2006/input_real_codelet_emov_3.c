#include <stdint.h>
#include <stdlib.h>

unsigned short *a;
unsigned short *b;
int i;

static unsigned short *a_storage;
static unsigned short *b_storage;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data: 524,288 elements (each unsigned short is 2 bytes)
    a_storage = (unsigned short *)calloc(data_size, sizeof(unsigned short));
    b_storage = (unsigned short *)calloc(data_size, sizeof(unsigned short));

    if (!a_storage || !b_storage) {
        exit(1);
    }

    a = a_storage;
    b = b_storage;
}