#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

tensor *x;
int i;

void init_vars() {
    int rank = 128 * 1024; // Adjust rank to achieve desired data size (~1MB-256MB)
    size_t total_size = sizeof(tensor) + (rank - 1) * sizeof(iodim);
    
    x = malloc(total_size);
    if (!x) exit(1);

    x->rnk = rank;
    for (int j = 0; j < rank; ++j) {
        x->dims[j].n = j + 1;
        x->dims[j].is = (j + 1) * 2;
        x->dims[j].os = 0; // Initialize to 0 before loop
    }
}