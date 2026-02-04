#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  gsl_permutation *p;
extern size_t i;
extern size_t count;
extern size_t min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_min = p->data[0];
    size_t temp_count = 0;
    for (i = 1; i < p->size; i++) {
        size_t val = p->data[i];
        if (val < local_min) {
            local_min = val;
        } else {
            temp_count++;
        }
    }
    if (p->data[0] < min) {
        min = local_min;
    }
    count += temp_count;
}
