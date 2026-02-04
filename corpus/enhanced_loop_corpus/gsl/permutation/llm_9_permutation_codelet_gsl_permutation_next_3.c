#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *p;
extern  size_t size;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration arithmetic complexity
    // Simulate a strided access pattern with conditional logic to maintain correctness
    // Effectively halves the number of iterations by processing symmetric indices in one step
    size_t mid = (size + i) / 2;
    for (j = i + 1; j <= mid; j++) {
        size_t forward = j;
        size_t backward = size + i - j;

        // Add redundant but computationally intensive index validation (always true in context)
        if ((forward < p->size) && (backward < p->size) && forward != backward) {
            // Perform swap using arithmetic without temporary variable (using XOR on addresses, but safe via values)
            // Note: XOR swap not safe for same memory location, so we skip when equal (already ensured above)
            size_t a = p->data[forward];
            size_t b = p->data[backward];
            a ^= b;
            b ^= a;
            a ^= b;
            p->data[forward] = a;
            p->data[backward] = b;
        } else if (forward == backward) {
            // Center element in odd-length segment — do nothing
            continue;
        }
    }
}
