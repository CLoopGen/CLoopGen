#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping (simulate gather pattern)
    for (i = 0; i < N - 2; i++) {
        int idx = dindex[i]; // Use dindex as source of indirect indices
        if (idx >= 0 && idx < N)
            dindex[idx] = i + 2;
    }
}
