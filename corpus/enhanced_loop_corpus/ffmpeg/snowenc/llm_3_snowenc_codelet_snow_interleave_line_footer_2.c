#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int *i;
extern IDWTELEM *low;
extern IDWTELEM *high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided read and write pattern with alternating access
    // Introduce stride-2 traversal by skipping every other element in logical access,
    // simulating a scenario where only even indices of the original range are processed.
    int j;
    for (j = (*i); j >= 0; j -= 4) {
        int lo_idx1 = j;
        int lo_idx2 = j - 2;
        int hi_idx1 = j >> 1;
        int hi_idx2 = (j - 2) >> 1;

        if (j >= 0) {
            low[lo_idx1 + 1] = high[hi_idx1];
            low[lo_idx1]     = low[hi_idx1];
        }
        if (j >= 2) {
            low[lo_idx2 + 1] = high[hi_idx2];
            low[lo_idx2]     = low[hi_idx2];
        }
    }
}
