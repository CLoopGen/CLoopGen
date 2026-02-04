#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern gsl_histogram *hh;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via alternating forward and backward access pattern)
    size_t indices[397];
    for (size_t idx = 0; idx < 397; idx++) {
        indices[idx] = (idx % 2 == 0) ? idx : 396 - idx; // Create non-sequential access pattern
    }
    for (i = 0; i < 397; i++) {
        size_t pos = indices[i]; // Use indirect indexing
        if (h->range[pos] != hh->range[pos])
            status = 1;
        if (h->bin[pos] != hh->bin[pos])
            status = 1;
    }
}
