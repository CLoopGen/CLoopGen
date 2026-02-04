#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (j = 0; j < length; j += step) {
        if (j < length) bdig[j] = 7 - dig[length - j - 1];
        if (j + 1 < length) bdig[j + 1] = 7 - dig[length - (j + 1) - 1];
    }
}
