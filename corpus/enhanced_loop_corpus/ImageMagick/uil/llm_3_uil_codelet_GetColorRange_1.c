#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using byte offsets)
    // Use an auxiliary index array to traverse non-contiguously based on a pattern
    int stride_pattern[] = {1, 2, 1, 3, 1}; // Example pattern for indirect progression
    int pat_len = 5;
    int i = 0;
    char *q = start_color;

    for (; (*q != '-') && (*q != '\x00') && (q < start_color + 4095); ) {
        if (*q == '(') {
            for (q++; (*q != ')') && (*q != '\x00') && (q < start_color + 4096); q++)
                ;
            if (*q == '\x00')
                break;
        } else {
            // Apply next stride from pattern cyclically
            q += stride_pattern[i % pat_len];
            i++;
        }
    }
    p = (q >= start_color && q < start_color + 4096) ? q : start_color + 4095;
}
