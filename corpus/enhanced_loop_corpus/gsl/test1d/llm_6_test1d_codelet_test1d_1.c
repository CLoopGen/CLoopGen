#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i <= 397; i++) {
        j = i + 1;
        if (j <= 397) {
            h1->range[j] = 100. + j;
        }
    }
    // Introduce a forward dependency (RAW): each iteration computes value used in next
    // This creates a loop-carried dependence by deferring write to next index
    // First element is now handled in predecessor's iteration, except i=0
    // Ensure first element is set separately if needed, but loop covers all via predecessor
}
