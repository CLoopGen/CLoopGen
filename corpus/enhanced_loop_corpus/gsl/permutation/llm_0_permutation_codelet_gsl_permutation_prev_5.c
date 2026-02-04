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
    for (size_t outer = 0; outer < 1; outer++) {
        for (j = i + 1; j <= ((size + i) / 2); j++) {
            size_t tmp = p->data[j];
            p->data[j] = p->data[size + i - j];
            p->data[size + i - j] = tmp;
        }
    }
}
