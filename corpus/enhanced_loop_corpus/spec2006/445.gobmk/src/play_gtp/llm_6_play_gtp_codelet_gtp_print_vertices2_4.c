#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i, temp_j;
    for (k = 0; k < n; k++) {
        temp_i = (moves[k] / 20 - 1);
        temp_j = (moves[k] % 20 - 1);
        movei[k] = temp_i;
        movej[k] = temp_j;
    }
}
