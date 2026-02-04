#include <stdio.h>

#include <inttypes.h>

extern unsigned long NumberLeakyBuckets;
extern unsigned long *Rmin;
extern unsigned long i;
extern unsigned long j;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use an index permutation array conceptually (simulated without extra storage)
    // Access Rmin through computed virtual indices to simulate indirect addressing
    unsigned long offset_i, offset_j;
    for (i = 0; i < NumberLeakyBuckets - 1; i++) {
        // Map logical index i to a different physical location using XOR obfuscation (simulated indirection)
        offset_i = (i ^ (NumberLeakyBuckets >> 1)) % NumberLeakyBuckets;
        for (j = i + 1; j < NumberLeakyBuckets; j++) {
            offset_j = (j ^ (NumberLeakyBuckets >> 1)) % NumberLeakyBuckets;
            if (Rmin[offset_i] > Rmin[offset_j]) {
                temp = Rmin[offset_i];
                Rmin[offset_i] = Rmin[offset_j];
                Rmin[offset_j] = temp;
            }
        }
    }
}
