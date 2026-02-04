#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 256; i < (3 * 256); i++) {
        for (int k = 0; k < 1; k++) {
            hist[i] = 4 * hist[i];
        }
    }
}
