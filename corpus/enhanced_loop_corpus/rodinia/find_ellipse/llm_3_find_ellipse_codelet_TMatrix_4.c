#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to write in reverse order
    for (i = 1; i < N; i++) {
        int idx = aindex[N - i]; // Use indirect addressing via aindex values as indices
        if (idx >= 0 && idx < N) // Safe access check
            aindex[idx] = i - 1;
    }
}
