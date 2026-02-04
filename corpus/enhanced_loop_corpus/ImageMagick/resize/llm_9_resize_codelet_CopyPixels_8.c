#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern  Quantum *source;
extern  ssize_t source_offset;
extern Quantum *destination;
extern  ssize_t destination_offset;
extern  size_t channels;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with higher-level strided access and increased arithmetic per iteration.
    // Simulates processing in chunks with more complex indexing and mixed data scaling.
    // Each iteration handles two elements with conditional logic and scaled writes.
    ssize_t n = (ssize_t)channels;
    ssize_t dest_base = (ssize_t)channels * destination_offset;
    ssize_t src_base = source_offset * (ssize_t)channels;
    
    // Process two elements per iteration using stride of 2
    for (i = 0; i < n; i += 2) {
        // Introduce multiplicative scaling and offset modulation to increase arithmetic complexity
        ssize_t src_idx1 = src_base + i;
        ssize_t dst_idx1 = dest_base + i;
        destination[dst_idx1] = source[src_idx1] * 1.0f;

        // Add conditional behavior to simulate control-dependent computation
        if (i + 1 < n) {
            ssize_t src_idx2 = src_base + i + 1;
            ssize_t dst_idx2 = dest_base + i + 1;
            destination[dst_idx2] = source[src_idx2] * 1.0f;
        }
    }
}
