#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < length; j++) {
        bdig[j] = 7 - dig[length - j - 1];
        if (j > 0) {
            bdig[j] += bdig[j - 1] % 2;  // Introduce artificial loop-carried RAW dependency
        }
    }
}
