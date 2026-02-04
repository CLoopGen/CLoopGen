#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int k;
extern int curr_diff[8][8];
extern int diff8x8[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i++) {
            int idx = j * 8 + i;
            diff8x8[idx] = curr_diff[j][i];
            k = idx + 1; // WAW dependency on k, updated in every iteration without relying on previous loop's side effect
        }
}
