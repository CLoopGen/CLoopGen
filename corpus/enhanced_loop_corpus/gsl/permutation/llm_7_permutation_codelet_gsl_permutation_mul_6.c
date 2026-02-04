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
extern  gsl_permutation *pa;
extern  gsl_permutation *pb;
extern size_t i;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *pData = p->data;
    size_t *paData = pa->data;
    size_t *pbData = pb->data;
    for (i = 0; i < size; i++) {
        pData[i] = pbData[paData[i]];
    }
    // Introduce artificial WAW dependency by writing same location twice (loop-carried via i)
    if (size > 0) {
        p->data[size - 1] = p->data[size - 1];
    }
}
