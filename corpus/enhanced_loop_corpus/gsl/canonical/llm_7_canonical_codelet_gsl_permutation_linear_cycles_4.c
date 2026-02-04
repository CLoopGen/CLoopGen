#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t size;
extern  gsl_permutation *p;
extern size_t i;
extern size_t k;
extern size_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    count = 0;
    for (i = 0; i < size; i++) {
        size_t temp_k = p->data[i];
        size_t found_root = 0;

        for (size_t j = 0; j < size && !found_root; j++) {
            if (temp_k <= i) {
                found_root = 1;
            } else {
                temp_k = p->data[temp_k];
            }
        }

        if (temp_k == i) {
            count++;
        }
    }
}
