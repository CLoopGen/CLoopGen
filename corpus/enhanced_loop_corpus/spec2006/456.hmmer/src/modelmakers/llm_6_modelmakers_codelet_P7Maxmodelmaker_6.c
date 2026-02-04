#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = first; i != 0; i = tbck[i]) {
        temp = matassign[i];
        temp &= ~(1 << 3);
        temp |= (1 << 0);
        matassign[i] = temp;
    }
}
