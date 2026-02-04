#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int sad;
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access - flatten the 2D array traversal to exploit spatial locality
    int idx;
    for (idx = 0; idx < 64; idx++) {
        int val = m2[idx / 8][idx % 8];
        sad += ((val < 0) ? (-val) : val);
    }
}
