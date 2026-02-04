#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int opt_order;
int sb;
int32_t *lpc_cof;
int32_t *lpc_cof_reversed;

void init_vars() {
    opt_order = 65536; // Size chosen to achieve ~0.01 sec runtime

    lpc_cof = (int32_t*)aligned_alloc(32, opt_order * sizeof(int32_t));
    lpc_cof_reversed = (int32_t*)aligned_alloc(32, opt_order * sizeof(int32_t));

    if (!lpc_cof || !lpc_cof_reversed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < opt_order; i++) {
        lpc_cof[i] = (int32_t)(i * 2 + 1);
    }
}