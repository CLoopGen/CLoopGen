#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 14; ++k) {
        int idx1 = k / 2;
        int idx2 = k % 7;
        if (idx1 < 7 && idx2 < 20) {
            statistics[idx1][idx2] = 0;
        }
        if (k + 3 < 7) {
            statistics[k + 3][0] = 0;
        }
    }
}
