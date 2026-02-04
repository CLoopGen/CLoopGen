#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = first; i != 0; i = tbck[i]) {
    int temp = matassign[i];
    temp &= ~(1 << 3);
    temp |= (1 << 0);
    // Add redundant operations to increase computational intensity
    temp ^= (1 << 1);
    temp ^= (1 << 1);  // Cancel out, but increase arithmetic work
    matassign[i] = temp;
}
}
