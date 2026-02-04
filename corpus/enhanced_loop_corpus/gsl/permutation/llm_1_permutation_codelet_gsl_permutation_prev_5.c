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
    if (i + 1 <= ((size + i) / 2)) {
        for (j = i + 1; j <= ((size + i) / 2); j += 2) {
            size_t tmp1 = p->data[j];
            p->data[j] = p->data[size + i - j];
            p->data[size + i - j] = tmp1;

            if (j + 1 <= ((size + i) / 2)) {
                size_t tmp2 = p->data[j + 1];
                p->data[j + 1] = p->data[size + i - (j + 1)];
                p->data[size + i - (j + 1)] = tmp2;
            }
        }
    }
}
