#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    NPY_CLIP = 0,
    NPY_WRAP = 1,
    NPY_RAISE = 2
} NPY_CLIPMODE;

NPY_CLIPMODE *modes;
int n;
int i;

void init_vars() {
    n = 67108864;  // ~256MB: 67M elements * sizeof(NPY_CLIPMODE) ≈ 256MB (assuming 4 bytes per enum)
    modes = (NPY_CLIPMODE*)calloc(n, sizeof(NPY_CLIPMODE));
    if (!modes) {
        exit(1);
    }
    modes[0] = NPY_CLIP;
    i = 0;
}