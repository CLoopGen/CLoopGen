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
for (i = 0; i < 8; i++) {
    for (j = 0; j < 4; j++) {
        int diff_a = (a[j] << 1) - b[j - s] - b[j];
        int diff_b = (b[j] << 1) - a[j] - a[j + s];
        comb += (diff_a ^ (diff_a >> 31)) - (diff_a >> 31);
        comb += (diff_b ^ (diff_b >> 31)) - (diff_b >> 31);
    }
    a += s;
    b += s;
}
}
