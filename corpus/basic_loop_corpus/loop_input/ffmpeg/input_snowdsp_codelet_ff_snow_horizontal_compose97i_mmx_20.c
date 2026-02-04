#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
int w_l;
int i;
IDWTELEM *ref;

void init_vars() {
    w_l = 1 << 20; // Approximately 1MB of data for IDWTELEM (2 bytes each), so 2^19 elements
    b = aligned_alloc(16, w_l * sizeof(IDWTELEM));
    ref = aligned_alloc(16, w_l * sizeof(IDWTELEM));

    for (int j = 0; j < w_l; j++) {
        b[j] = (IDWTELEM)(rand() % 512);
        ref[j] = (IDWTELEM)(rand() % 512);
    }

    i = 0;
}