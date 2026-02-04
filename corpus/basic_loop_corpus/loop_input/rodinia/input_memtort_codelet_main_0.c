#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

static int *ive_x = NULL;
static int *ive_y = NULL;
static IVEC ix_storage;
static IVEC iy_storage;

IVEC *ix = &ix_storage;
IVEC *iy = &iy_storage;
int i = 0;

void init_vars() {
    const size_t data_size_bytes = 128 * 1024 * 1024; // 128 MB target
    const size_t element_size = sizeof(int);
    const u_int estimated_elements = data_size_bytes / (2 * element_size); // two arrays

    ive_x = (int*)calloc(estimated_elements, element_size);
    ive_y = (int*)calloc(estimated_elements, element_size);

    if (!ive_x || !ive_y) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    ix->ive = ive_x;
    iy->ive = ive_y;
    ix->dim = estimated_elements;
    iy->dim = estimated_elements;
    ix->max_dim = estimated_elements;
    iy->max_dim = estimated_elements;
}