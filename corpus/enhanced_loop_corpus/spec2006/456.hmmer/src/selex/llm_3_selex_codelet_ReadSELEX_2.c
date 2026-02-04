#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Mapping
    // Use an auxiliary index array to access aseqs in a non-sequential, indirect manner
    // Simulate permutation: access elements in reverse order indirectly
    int *indices = (int*)__builtin_alloca(num * sizeof(int));
    int idx;
    for (idx = 0; idx < num; idx++) {
        indices[idx] = num - 1 - idx; // reverse mapping
    }
    for (idx = 0; idx < num; idx++) {
        int mapped_idx = indices[idx];
        aseqs[mapped_idx][alen] = '\x00';
    }
}
