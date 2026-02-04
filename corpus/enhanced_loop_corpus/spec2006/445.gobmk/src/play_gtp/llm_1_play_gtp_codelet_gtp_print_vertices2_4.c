#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        k = 0;
        for (int block = 0; block < n; block += 1) {
            k = block;
            movei[k] = ((moves[k]) / (19 + 1) - 1);
            movej[k] = ((moves[k]) % (19 + 1) - 1);
        }
    }
}
