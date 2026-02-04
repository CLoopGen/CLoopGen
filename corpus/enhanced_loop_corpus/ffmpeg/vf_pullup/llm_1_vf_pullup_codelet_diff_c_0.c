#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    diff += (((a[i % 8] - b[i % 8]) ^ ((a[i % 8] - b[i % 8]) >> 31)) - ((a[i % 8] - b[i % 8]) >> 31));
    if ((i + 1) % 8 == 0) {
        a += s;
        b += s;
    }
}
}
