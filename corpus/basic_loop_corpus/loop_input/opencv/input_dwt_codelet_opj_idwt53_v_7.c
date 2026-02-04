#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 nb_cols;
OPJ_INT32 c;
OPJ_INT32 *tiledp_col;

void init_vars() {
    nb_cols = 67108864; // Approximately 256MB / sizeof(OPJ_INT32) = 67M elements
    OPJ_INT32 *base_ptr = (OPJ_INT32*)calloc(nb_cols, sizeof(OPJ_INT32));
    if (!base_ptr) {
        exit(1);
    }
    for (OPJ_INT32 i = 0; i < nb_cols; i++) {
        base_ptr[i] = 1024;
    }
    tiledp_col = base_ptr;
}