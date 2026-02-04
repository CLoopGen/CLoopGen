#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double P[];
extern double num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward array access with reversed index mapping
    // Instead of counting down from 4 to 0, count up and compute reverse index
    num = 1.0; // ensure initialization
    for (i = 0; i < 5; ++i) {
        int rev_index = 4 - i; // map 0->4, 1->3, ..., 4->0 for consecutive upward loop
        num = x * num + P[rev_index];
    }
}
