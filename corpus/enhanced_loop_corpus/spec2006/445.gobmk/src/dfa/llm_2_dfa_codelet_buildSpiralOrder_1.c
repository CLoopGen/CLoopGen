#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D-like index into a sequential pattern
    int idx = 4 * 21 * 21 + 21; // Starting index corresponding to i=21, j=21
    for (i = 21; i < 21 * 3; i++) {
        for (j = 21; j < 21 * 3; j++) {
            mark[idx] = 0;
            idx++;
        }
        idx += 4 * 21 - (21 * 3 - 21); // Skip over non-inner elements if needed (though not necessary here due to direct increment)
    }
}
