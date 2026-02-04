#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *hist;
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 72; i++) {
        int offset = 72 - i;
        for (int k = 0; k < 1; k++) {
            vector[offset] = hist[i];
        }
    }
}
