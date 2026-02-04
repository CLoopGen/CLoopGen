#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective trip count by skipping every other element
for (i = first; i != 0; i = tbck[tbck[i]]) {
    if (i != 0) {
        matassign[i] &= ~(1 << 3);
        matassign[i] |= (1 << 0);
    }
    // Ensure inner consistency with an additional conditional check
    if (tbck[i] != 0) {
        int j = tbck[i];
        matassign[j] &= ~(1 << 3);
        matassign[j] |= (1 << 0);
    }
}
}
