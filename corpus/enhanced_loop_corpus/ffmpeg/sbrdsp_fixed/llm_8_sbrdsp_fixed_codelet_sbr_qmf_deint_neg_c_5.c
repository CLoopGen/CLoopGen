#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v;
extern  int *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        int idx1 = 63 - i;
        int idx2 = 63 - i - 1;
        int src_val1 = src[63 - i];
        int src_val2 = src[63 - i - 1];
        v[i] = (int)((16U + src_val1) >> 5);
        if (idx1 < 64) v[idx1] = (int)((16U - src_val2) >> 5);
    }
}
