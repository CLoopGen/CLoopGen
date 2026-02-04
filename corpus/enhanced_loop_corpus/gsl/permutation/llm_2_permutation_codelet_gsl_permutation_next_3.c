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
    // Variant 1: Strided memory access with step of 2
    // Instead of consecutive j increments, we now process every second element
    // Adjust loop bounds to ensure we stay within valid index range
    size_t start = i + 1;
    size_t end = (size + i) / 2;
    for (j = start; j <= end; j += 2) {
        size_t tmp = p->data[j];
        p->data[j] = p->data[size + i - j];
        p->data[size + i - j] = tmp;

        // Handle next index (j+1) if within bounds
        size_t j_next = j + 1;
        if (j_next <= end) {
            size_t tmp_next = p->data[j_next];
            p->data[j_next] = p->data[size + i - j_next];
            p->data[size + i - j_next] = tmp_next;
        }
    }
}
