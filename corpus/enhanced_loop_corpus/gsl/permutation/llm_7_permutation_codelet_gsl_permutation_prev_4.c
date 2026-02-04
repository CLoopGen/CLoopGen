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
    size_t local_k = k;
    for (j = i + 2; j < size; j += 2) {
        size_t data_i = p->data[i];
        size_t data_k = p->data[local_k];
        if (j + 1 < size) {
            size_t data_j1 = p->data[j];
            size_t data_j2 = p->data[j+1];
            int cond1 = (data_j1 < data_i) && (data_j1 > data_k);
            int cond2 = (data_j2 < data_i) && (data_j2 > data_k);
            if (cond1 && cond2) {
                local_k = (data_j1 > data_j2) ? j : j+1;
            } else if (cond1) {
                local_k = j;
            } else if (cond2) {
                local_k = j+1;
            }
        } else {
            if ((p->data[j] < p->data[i]) && (p->data[j] > p->data[local_k])) {
                local_k = j;
            }
        }
    }
    k = local_k;
}
