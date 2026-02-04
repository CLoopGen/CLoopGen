#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern int *diff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 8; i += 8) {
        for (int k = 0; k < 8 && (i + k) < len; k++) {
            diff[i + k] <<= 7;
        }
    }
}
