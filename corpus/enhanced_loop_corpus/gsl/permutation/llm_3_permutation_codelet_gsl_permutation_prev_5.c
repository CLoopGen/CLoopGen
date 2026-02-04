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
    // Variant 2: Indirect memory access using an index remapping array (simulated statically)
    size_t *indices = (size_t*)alloca(sizeof(size_t) * (((size + i) / 2 - i)));
    size_t idx_count = 0;
    for (size_t k = i + 1; k <= ((size + i) / 2); k++) {
        indices[idx_count++] = k;
    }
    
    for (size_t idx = 0; idx < idx_count; idx++) {
        j = indices[idx];
        size_t tmp = p->data[j];
        p->data[j] = p->data[size + i - j];
        p->data[size + i - j] = tmp;
    }
}
