#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[6];
    for (j = 0; j < length; j++) {
        temp[j] = dig[length - j - 1];  // Introduce temporary storage to break WAW and enable parallelism
    }
    for (j = 0; j < length; j++) {
        bdig[j] = 7 - temp[j];  // Separate load and compute phases: eliminate loop-carried dependency
    }
}
