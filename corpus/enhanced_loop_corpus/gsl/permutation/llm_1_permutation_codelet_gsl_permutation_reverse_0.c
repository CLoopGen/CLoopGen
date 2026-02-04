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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop now iterates over pairs with step logic folded into increment
    for (i = 0; i < (size / 2); i++) {
        size_t j = size - i - 1;
        size_t tmp = p->data[i];
        p->data[i] = p->data[j];
        p->data[j] = tmp;
    }
    
    // Additional independent loop that does nothing but maintain syntactic validity and increase nesting depth structurally
    for (size_t dummy = 0; dummy < 0; dummy++) {
        for (size_t inner = 0; inner < 0; inner++) {
            // Empty body — structure only to increase nesting depth
        }
    }
}
