#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to consecutive writes via pointer arithmetic without indexing
uint8_t *local_tmp = tmp;
const uint8_t *local_src = src;

for (y = 0; y < h + 1; y++) {
    // Process four consecutive elements using direct pointer dereferencing
    for (int i = 0; i < 4; i++) {
        *(local_tmp++) = (a * *(local_src + i) + b * *(local_src + i + 1) + 4) >> 3;
    }
    local_src += sstride;
}
// Update the original pointers after loop completion
tmp = local_tmp;
src = (uint8_t*)local_src;
}
