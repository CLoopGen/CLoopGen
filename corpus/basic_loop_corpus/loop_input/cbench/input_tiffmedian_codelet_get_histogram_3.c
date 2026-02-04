#include <stdio.h>
#include <inttypes.h>

typedef unsigned int uint32;

uint32 i;
int *ptr;

static int *ptr_storage;
static uint32 array_size;
static int default_array[8 << 20]; // ~32 MB of data (8M elements)

void init_vars() {
    array_size = (1UL << 5) * (1UL << 5) * (1UL << 5); // 32*32*32 = 32768
    ptr_storage = default_array;
    ptr = ptr_storage;
    i = array_size;
}