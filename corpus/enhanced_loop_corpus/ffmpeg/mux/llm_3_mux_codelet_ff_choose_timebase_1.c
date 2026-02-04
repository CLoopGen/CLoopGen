#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

extern int min_precision;
extern AVRational q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Simulate indirect memory access via jump table or index indirection
    // Use an array of potential divisors to create indirect access pattern
    // Eliminate while by using a controlled for-loop with precomputed factors
    
    int divisors[12] = {2,3,4,5,6,7,8,9,10,11,12,13}; // possible j values
    int indices[12] = {0,1,2,3,4,5,6,7,8,9,10,11};  // indirect index mapping (could be reordered for indirect pattern)
    
    for (int idx = 0; idx < 12; idx++) {
        j = divisors[indices[idx]];  // indirect access via indices
        if (j >= 14) continue;
        
        // Unroll the condition formerly in while as a bounded for-loop
        for (int k = 0; k < 32 && q.den / q.num < min_precision && q.num % j == 0; k++) {
            q.num /= j;
        }
    }
}
