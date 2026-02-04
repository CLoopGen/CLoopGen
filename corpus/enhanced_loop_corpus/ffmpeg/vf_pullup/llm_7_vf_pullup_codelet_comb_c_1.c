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
    int j0, j1, j2, j3, j4, j5, j6, j7;
    j0 = 0; j1 = 1; j2 = 2; j3 = 3; j4 = 4; j5 = 5; j6 = 6; j7 = 7;
    comb += ((((a[j0] << 1) - b[j0 - s] - b[j0]) ^ (((a[j0] << 1) - b[j0 - s] - b[j0]) >> 31)) - (((a[j0] << 1) - b[j0 - s] - b[j0]) >> 31)) +
           ((((b[j0] << 1) - a[j0] - a[j0 + s]) ^ (((b[j0] << 1) - a[j0] - a[j0 + s]) >> 31)) - (((b[j0] << 1) - a[j0] - a[j0 + s]) >> 31));
    comb += ((((a[j1] << 1) - b[j1 - s] - b[j1]) ^ (((a[j1] << 1) - b[j1 - s] - b[j1]) >> 31)) - (((a[j1] << 1) - b[j1 - s] - b[j1]) >> 31)) +
           ((((b[j1] << 1) - a[j1] - a[j1 + s]) ^ (((b[j1] << 1) - a[j1] - a[j1 + s]) >> 31)) - (((b[j1] << 1) - a[j1] - a[j1 + s]) >> 31));
    comb += ((((a[j2] << 1) - b[j2 - s] - b[j2]) ^ (((a[j2] << 1) - b[j2 - s] - b[j2]) >> 31)) - (((a[j2] << 1) - b[j2 - s] - b[j2]) >> 31)) +
           ((((b[j2] << 1) - a[j2] - a[j2 + s]) ^ (((b[j2] << 1) - a[j2] - a[j2 + s]) >> 31)) - (((b[j2] << 1) - a[j2] - a[j2 + s]) >> 31));
    comb += ((((a[j3] << 1) - b[j3 - s] - b[j3]) ^ (((a[j3] << 1) - b[j3 - s] - b[j3]) >> 31)) - (((a[j3] << 1) - b[j3 - s] - b[j3]) >> 31)) +
           ((((b[j3] << 1) - a[j3] - a[j3 + s]) ^ (((b[j3] << 1) - a[j3] - a[j3 + s]) >> 31)) - (((b[j3] << 1) - a[j3] - a[j3 + s]) >> 31));
    comb += ((((a[j4] << 1) - b[j4 - s] - b[j4]) ^ (((a[j4] << 1) - b[j4 - s] - b[j4]) >> 31)) - (((a[j4] << 1) - b[j4 - s] - b[j4]) >> 31)) +
           ((((b[j4] << 1) - a[j4] - a[j4 + s]) ^ (((b[j4] << 1) - a[j4] - a[j4 + s]) >> 31)) - (((b[j4] << 1) - a[j4] - a[j4 + s]) >> 31));
    comb += ((((a[j5] << 1) - b[j5 - s] - b[j5]) ^ (((a[j5] << 1) - b[j5 - s] - b[j5]) >> 31)) - (((a[j5] << 1) - b[j5 - s] - b[j5]) >> 31)) +
           ((((b[j5] << 1) - a[j5] - a[j5 + s]) ^ (((b[j5] << 1) - a[j5] - a[j5 + s]) >> 31)) - (((b[j5] << 1) - a[j5] - a[j5 + s]) >> 31));
    comb += ((((a[j6] << 1) - b[j6 - s] - b[j6]) ^ (((a[j6] << 1) - b[j6 - s] - b[j6]) >> 31)) - (((a[j6] << 1) - b[j6 - s] - b[j6]) >> 31)) +
           ((((b[j6] << 1) - a[j6] - a[j6 + s]) ^ (((b[j6] << 1) - a[j6] - a[j6 + s]) >> 31)) - (((b[j6] << 1) - a[j6] - a[j6 + s]) >> 31));
    comb += ((((a[j7] << 1) - b[j7 - s] - b[j7]) ^ (((a[j7] << 1) - b[j7 - s] - b[j7]) >> 31)) - (((a[j7] << 1) - b[j7 - s] - b[j7]) >> 31)) +
           ((((b[j7] << 1) - a[j7] - a[j7 + s]) ^ (((b[j7] << 1) - a[j7] - a[j7 + s]) >> 31)) - (((b[j7] << 1) - a[j7] - a[j7 + s]) >> 31));
    a += s;
    b += s;
}
}
