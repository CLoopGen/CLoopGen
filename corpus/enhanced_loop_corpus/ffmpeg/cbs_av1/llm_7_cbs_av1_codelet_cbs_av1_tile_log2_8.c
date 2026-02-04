#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_k = 0;
    int next_k = 0;
    for (int i = 0; i < 32; i++) {
        next_k = prev_k + 1;
        int shift_val = blksize << prev_k;
        int meets_target = shift_val < target;
        k = meets_target ? next_k : prev_k;
        prev_k = k;
        if (!meets_target) break;
    }
}
