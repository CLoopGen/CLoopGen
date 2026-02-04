#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    long *indices = (long*)malloc(Nr * sizeof(long));
    if (!indices) return;
    for (long j = 0; j < Nr; j++) {
        indices[j] = j; // Simulate non-trivial index computation (e.g., could be permuted)
    }
    for (i = 0; i < Nr; i++) {
        long idx = indices[i]; // Use indirect addressing
        iN[idx] = idx - 1;
        iS[idx] = idx + 1;
    }
    free(indices);
}
