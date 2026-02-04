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
    int local_diff[4];
    for (i = 0; i < 4; i++) {
        local_diff[i] = 0;
        for (j = 0; j < 8; j++) {
            int adj_diff = a[j] - b[j];
            local_diff[i] += ((adj_diff ^ (adj_diff >> 31)) - (adj_diff >> 31));
        }
        a += s;
        b += s;
    }
    for (i = 0; i < 4; i++) {
        diff += local_diff[i];
    }
}
