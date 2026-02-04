#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

static int *generated_ive = NULL;
static IVEC ix_store;
IVEC *ix = &ix_store;
int i;

void init_vars() {
    ix_store.dim = 32000000; // Approx. 128 MB of data (32M * 4 bytes), targets ~0.01 sec on modern CPU
    ix_store.max_dim = ix_store.dim;
    generated_ive = (int*)calloc(ix_store.dim, sizeof(int));
    if (!generated_ive) {
        exit(1);
    }
    ix_store.ive = generated_ive;
}