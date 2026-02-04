#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int index[361];
    for (k = 0; k < n; k++) {
        index[k] = k;
    }
    for (k = 0; k < n; k++) {
        int pos = index[k]; // Indirect access via index array
        movei[pos] = ((moves[pos]) / (19 + 1) - 1);
        movej[pos] = ((moves[pos]) % (19 + 1) - 1);
    }
}
