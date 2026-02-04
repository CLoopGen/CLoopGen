#include <stdint.h>
#include <string.h>

unsigned int *d;
unsigned int i;

static unsigned int d_storage[256];

void init_vars() {
    d = d_storage;
}