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
    for (j = 0; j < 8; j++)
        comb += ((((a[j] << 1) - b[j - s] - b[j]) ^ (((a[j] << 1) - b[j - s] - b[j]) >> 31)) - (((a[j] << 1) - b[j - s] - b[j]) >> 31)) + ((((b[j] << 1) - a[j] - a[j + s]) ^ (((b[j] << 1) - a[j] - a[j + s]) >> 31)) - (((b[j] << 1) - a[j] - a[j + s]) >> 31));
    a += s;
    b += s;
}

}
