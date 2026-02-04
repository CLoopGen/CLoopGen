#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

static int *in_ive_ptr = NULL;
static int *out_ive_ptr = NULL;

IVEC *in = NULL;
IVEC *out = NULL;
int i = 0;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; // ~64 MB of data for ~0.01 sec runtime estimate
    const size_t num_ints = data_size_bytes / sizeof(int);
    
    in_ive_ptr = (int*)calloc(num_ints, sizeof(int));
    out_ive_ptr = (int*)calloc(num_ints, sizeof(int));
    
    if (!in_ive_ptr || !out_ive_ptr) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < num_ints; idx++) {
        in_ive_ptr[idx] = rand();
    }
    
    in = (IVEC*)malloc(sizeof(IVEC));
    out = (IVEC*)malloc(sizeof(IVEC));
    
    if (!in || !out) {
        fprintf(stderr, "Failed to allocate IVEC structures\n");
        exit(1);
    }
    
    in->dim = (u_int)num_ints;
    in->max_dim = (u_int)num_ints;
    in->ive = in_ive_ptr;
    
    out->dim = (u_int)num_ints;
    out->max_dim = (u_int)num_ints;
    out->ive = out_ive_ptr;
}