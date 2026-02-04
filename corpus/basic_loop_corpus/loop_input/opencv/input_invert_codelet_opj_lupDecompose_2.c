#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 nb_compo = 65536; // ~256KB of data (65536 * 4 bytes)
OPJ_UINT32 *tmpPermutations;
OPJ_UINT32 i;

void init_vars() {
    tmpPermutations = (OPJ_UINT32*)malloc(nb_compo * sizeof(OPJ_UINT32));
    if (!tmpPermutations) {
        exit(1);
    }
}