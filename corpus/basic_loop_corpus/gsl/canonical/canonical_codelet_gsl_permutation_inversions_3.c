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
extern size_t count;
extern size_t i;
extern size_t j;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
        if (p->data[i] > p->data[j]) {
            count++;
        }
    }
}

}
