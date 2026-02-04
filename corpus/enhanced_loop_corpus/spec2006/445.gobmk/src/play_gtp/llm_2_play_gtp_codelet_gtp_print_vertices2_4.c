#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (k = 0; k < n; k += stride) {
        if (k >= n) break;
        movei[k] = ((moves[k]) / (19 + 1) - 1);
        movej[k] = ((moves[k]) % (19 + 1) - 1);
    }
    for (k = 1; k < n; k += stride) {
        movei[k] = ((moves[k]) / (19 + 1) - 1);
        movej[k] = ((moves[k]) % (19 + 1) - 1);
    }
}
