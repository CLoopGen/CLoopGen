#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = length * 2;
    for (j = 0; j < limit; j++) {
        if (j % 2 == 0) {
            int idx = j / 2;
            bdig[idx] = 7 - dig[length - idx - 1];
        }
    }
}
