#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (k = 0; k < n; k++) {
        i = moves[k];
        movei[k] = (i / 20 - 1);
        movej[k] = (i % 20 - 1);
    }
}
