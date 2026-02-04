#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern using array indexing with stride
    // Simulate memory access pattern by treating 'temp' as accumulator over strided indices
    long *temp_ptr = &temp;
    int stride = 2; // Access every second logical element (conceptual stride)
    for (i = 1; i < nc; i += stride) {
        if (i < nc) {
            *temp_ptr *= iroot;
        }
        // Insert dummy operation to simulate strided traversal effect
        if (i + 1 < nc) {
            *temp_ptr += 1; // Dummy update to maintain realism
        }
    }
}
