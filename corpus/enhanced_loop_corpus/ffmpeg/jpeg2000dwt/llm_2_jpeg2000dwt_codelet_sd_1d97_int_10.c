#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic and loop unrolling by 2
    int *base = p + ((i0 >> 1) - 1) * 2;
    int limit = (i1 >> 1) - (i0 >> 1) + 1;
    for (i = 0; i < limit; i++) {
        int temp0 = base[2*i+0];
        int temp2 = base[2*i+2];
        int sum = temp0 + temp2;
        base[2*i+1] += (57862LL * sum + (1 << 15)) >> 16;
        if (i + 1 < limit) {
            int next_sum = base[2*(i+1)+0] + base[2*(i+1)+2];
            base[2*(i+1)+1] += (57862LL * next_sum + (1 << 15)) >> 16;
            i++;
        }
    }
}
