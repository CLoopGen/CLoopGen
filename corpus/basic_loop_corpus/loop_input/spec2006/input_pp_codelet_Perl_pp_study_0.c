#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int I32;

I32 ch;
I32 *sfirst;
I32 *sfirst_base;

void init_vars() {
    const size_t array_size = 1 << 20; // 1MB of data (about 4 million bytes for I32)
    sfirst_base = (I32*)calloc(array_size, sizeof(I32));
    sfirst = sfirst_base;
}