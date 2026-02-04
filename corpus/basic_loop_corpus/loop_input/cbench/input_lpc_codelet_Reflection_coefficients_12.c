#include <stdio.h>
#include <inttypes.h>

typedef short word;

word *r;
int i;

static word array[131072]; // 256KB of data (131072 elements * 2 bytes)

void init_vars() {
    r = array;
    i = 131072;
}