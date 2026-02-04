#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

static int *ive_data;
static IVEC ix_storage;
IVEC *ix = &ix_storage;
int i;

void init_vars() {
    ix->dim = 10;
    ix->max_dim = 10;
    ive_data = (int *)calloc(10, sizeof(int));
    if (!ive_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    ix->ive = ive_data;
}