#include <stdlib.h>
#include <stdint.h>

typedef int32_t INT32;

int i;
INT32 *bptr;

INT32 *array_base;
int array_size;

void init_vars() {
    array_size = 64 * 1024 * 1024 / sizeof(INT32);
    array_base = (INT32*)calloc(array_size, sizeof(INT32));
    bptr = array_base;
}