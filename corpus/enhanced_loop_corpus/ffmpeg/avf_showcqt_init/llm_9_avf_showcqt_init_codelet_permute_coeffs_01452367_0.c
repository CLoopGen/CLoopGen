#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < len; k++) {
        int offset = k % 4;
        if (offset == 0 && k + 4 < len && k + 2 < len) {
            float SWAP_tmp = v[k + 4];
            v[k + 4] = v[k + 2];
            v[k + 2] = SWAP_tmp;
        } else if (offset == 1 && k + 5 < len && k + 3 < len) {
            float SWAP_tmp = v[k + 5];
            v[k + 5] = v[k + 3];
            v[k + 3] = SWAP_tmp;
        }
    }
}
