#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < len; k += 8) {
        for (int j = 4; j <= 5; ++j) {
            int idx = (j == 4) ? 2 : 3;
            float SWAP_tmp = v[k + j];
            v[k + j] = v[k + idx];
            v[k + idx] = SWAP_tmp;
        }
    }
}
