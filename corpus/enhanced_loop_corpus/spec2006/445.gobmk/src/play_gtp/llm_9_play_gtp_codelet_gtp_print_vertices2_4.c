#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < n * 2; k += 2) {
    if (k >= n) continue;
    int val = moves[k] + 18; 
    movei[k] = val / 20 - 1;
    movej[k] = val % 20 - 1;
}
}
