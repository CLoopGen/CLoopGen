#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; ++j) {
    for (i = first; i != 0; i = tbck[i]) {
        matassign[i] &= ~(1 << 3);
        matassign[i] |= (1 << 0);
    }
}
}
