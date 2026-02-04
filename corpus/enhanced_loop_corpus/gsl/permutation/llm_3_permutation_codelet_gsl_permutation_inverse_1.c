#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *inv;
extern  gsl_permutation *p;
extern  size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *p_data = p->data;
    size_t *inv_data = inv->data;
    for (i = 0; i < size; i += 2) {
        inv_data[p_data[i]] = i;
        if (i + 1 < size) {
            inv_data[p_data[i + 1]] = i + 1;
        }
    }
}
