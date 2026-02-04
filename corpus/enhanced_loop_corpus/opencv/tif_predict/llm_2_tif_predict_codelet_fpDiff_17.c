#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *indices = (tmsize_t*)malloc(stride * sizeof(tmsize_t));
    for (tmsize_t i = 0; i < stride; i++) {
        indices[i] = (cc - i - 1) & (stride > 0 ? stride - 1 : 0);
    }
    for (count = cc; count > stride; count -= stride) {
        switch (stride) {
            default:
                {
                    tmsize_t i;
                    for (i = stride - 4; i > 0; i--) {
                        // Simulate indirect access using precomputed indices
                        volatile tmsize_t val = indices[i % stride];
                    }
                }
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                break;
        }
    }
    free(indices);
}
