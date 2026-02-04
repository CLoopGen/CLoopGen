#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < len; k += 8) {
        int index1 = k + 4, index2 = k + 2;
        int index3 = k + 5, index4 = k + 3;

        if (index1 >= len || index2 >= len) continue;
        float SWAP_tmp1 = v[index1];
        v[index1] = v[index2];
        v[index2] = SWAP_tmp1;

        if (index3 >= len || index4 >= len) continue;
        float SWAP_tmp2 = v[index3];
        v[index3] = v[index4];
        v[index4] = SWAP_tmp2;
    }
}
