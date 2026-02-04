#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

IVEC *iv1;
u_int i;
int *out_ive;
int *iv1_ive;
int *iv2_ive;

void init_vars() {
    const size_t data_size = 32 * 1024 * 1024; // ~128 MB of total integer data (32M ints)
    
    iv1 = (IVEC*)malloc(sizeof(IVEC));
    if (!iv1) exit(1);

    iv1->dim = data_size / sizeof(int);
    iv1->max_dim = iv1->dim;

    iv1_ive = (int*)malloc(data_size);
    iv2_ive = (int*)malloc(data_size);
    out_ive = (int*)malloc(data_size);

    if (!iv1_ive || !iv2_ive || !out_ive) exit(1);

    for (size_t idx = 0; idx < iv1->dim; idx++) {
        iv1_ive[idx] = rand();
        iv2_ive[idx] = rand();
        out_ive[idx] = 0;
    }
}