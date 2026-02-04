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
        for (int i = 0; i < 1; ++i) {
            float SWAP_tmp = v[k + 4];
            v[k + 4] = v[k + 2];
            v[k + 2] = SWAP_tmp;
        }
        for (int i = 0; i < 1; ++i) {
            float SWAP_tmp = v[k + 5];
            v[k + 5] = v[k + 3];
            v[k + 3] = SWAP_tmp;
        }
    }
}
