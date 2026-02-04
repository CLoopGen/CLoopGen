#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int comb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    j = 0;
    if (j < 8) {
        do {
            comb += ((((a[j] << 1) - b[j - s] - b[j]) ^ (((a[j] << 1) - b[j - s] - b[j]) >> 31)) - (((a[j] << 1) - b[j - s] - b[j]) >> 31)) + ((((b[j] << 1) - a[j] - a[j + s]) ^ (((b[j] << 1) - a[j] - a[j + s]) >> 31)) - (((b[j] << 1) - a[j] - a[j + s]) >> 31));
            j++;
        } while (j < 8);
    }
    a += s;
    b += s;
}
}
