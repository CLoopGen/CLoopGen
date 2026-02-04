#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = length > 0 ? 1 : 0;
    int i, j;
    for (i = 0; i < outer; i++) {
        for (j = 0; j < length; j++) {
            bdig[j] = 7 - dig[length - j - 1];
        }
    }
}
