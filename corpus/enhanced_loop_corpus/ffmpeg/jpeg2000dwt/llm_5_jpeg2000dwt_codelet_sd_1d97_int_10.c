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
    for (i = (i0 >> 1) - 1; i < (i1 >> 1); i++) {
        int temp_sum = p[2 * i] + p[2 * i + 2];
        if (temp_sum > 0)
            p[2 * i + 1] += (57862LL * temp_sum + (1 << 15)) >> 16;
        else if (temp_sum < 0)
            p[2 * i + 1] -= (57862LL * (-temp_sum) + (1 << 15)) >> 16;
    }
}
