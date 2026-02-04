#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using reverse index mapping
    for (i = 1; i < N; i++) {
        int rev_index = N - 1 - i;
        if (rev_index >= 1 && rev_index < N)
            aindex[rev_index] = i - 1;
    }
}
