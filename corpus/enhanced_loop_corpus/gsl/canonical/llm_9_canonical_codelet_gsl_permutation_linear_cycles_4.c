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



void loop() {
    count = 0;
    for (i = 0; i < size; i += 2) {
        size_t k1 = p->data[i];
        size_t k2 = (i + 1 < size) ? p->data[i + 1] : 0;
        size_t prev_k1, prev_k2;

        do {
            prev_k1 = k1;
            if (k1 > i) {
                k1 = p->data[k1];
            }
        } while (k1 != prev_k1 && k1 > i);

        if (i + 1 < size) {
            do {
                prev_k2 = k2;
                if (k2 > i + 1) {
                    k2 = p->data[k2];
                }
            } while (k2 != prev_k2 && k2 > i + 1);
        }

        if (k1 == i) count++;
        if (i + 1 < size && k2 == i + 1) count++;
    }
}
