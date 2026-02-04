#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ndim;
int *out_strideperm;
int i0;

void init_vars() {
    ndim = 65536; // Size chosen to achieve ~0.01 sec runtime
    out_strideperm = (int*)malloc(ndim * sizeof(int));
    if (!out_strideperm) {
        exit(1);
    }
}

void loop(); // Forward declaration

// Ensure proper linkage and execution when called from elsewhere