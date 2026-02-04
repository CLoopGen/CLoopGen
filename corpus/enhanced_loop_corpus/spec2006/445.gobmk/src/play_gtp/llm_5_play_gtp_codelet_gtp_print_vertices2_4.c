#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < n; k++) {
    int temp = moves[k];
    if (temp > 0) {
        movei[k] = (temp / 20 - 1);
        movej[k] = (temp % 20 - 1);
    } else {
        movei[k] = -1;
        movej[k] = -1;
    }
}
}
