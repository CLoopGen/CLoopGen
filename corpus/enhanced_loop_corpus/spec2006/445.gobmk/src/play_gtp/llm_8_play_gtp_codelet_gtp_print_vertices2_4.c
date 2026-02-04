#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k1;
for (k = 0, k1 = 0; k < n && k1 < n; k++, k1++) {
    int temp = moves[k] - 1;
    movei[k] = temp / 20;
    movej[k] = temp % 20;
}
}
