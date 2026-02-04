#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_combination_struct {
    size_t n;
    size_t k;
    size_t *data;
};


typedef struct gsl_combination_struct gsl_combination;

extern gsl_combination *c;
extern  size_t k;
extern size_t i;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < k; i++) {
    c->data[i] = n - k + i;
}

}
