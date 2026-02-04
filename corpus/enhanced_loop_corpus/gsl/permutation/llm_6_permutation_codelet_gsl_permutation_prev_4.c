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
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_k = k;
    for (j = i + 2; j < size; j++) {
        size_t current_data_j = p->data[j];
        if ((current_data_j < p->data[i]) && (current_data_j > p->data[temp_k])) {
            temp_k = j;
        }
    }
    k = temp_k;
}
