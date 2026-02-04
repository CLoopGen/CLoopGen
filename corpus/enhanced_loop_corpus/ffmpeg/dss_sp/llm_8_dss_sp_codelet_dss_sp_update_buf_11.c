#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *hist;
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 72; i += 3) {
        vector[72 - i] = hist[i];
        if (i + 1 < 72) vector[72 - (i + 1)] = hist[i + 1];
        if (i + 2 < 72) vector[72 - (i + 2)] = hist[i + 2];
    }
}
