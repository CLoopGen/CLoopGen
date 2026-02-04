#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

static double *generated_ve = NULL;
static VEC xn_storage;
VEC *xn = &xn_storage;
int i;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // ~128MB of double data (~16M elements)
    size_t num_elements = data_size / sizeof(double);
    
    generated_ve = (double*)calloc(num_elements, sizeof(double));
    if (!generated_ve) {
        exit(1);
    }
    
    xn->dim = (u_int)num_elements;
    xn->max_dim = (u_int)num_elements;
    xn->ve = generated_ve;
}