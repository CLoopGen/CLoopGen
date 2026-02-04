#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = -1;
    for (i = first; i != 0; i = tbck[i]) {
        if (prev_i != -1) {
            matassign[prev_i] |= (1 << 0); 
        }
        matassign[i] &= ~(1 << 3);
        prev_i = i;
    }
    if (prev_i != -1) {
        matassign[prev_i] |= (1 << 0);
    }
}
