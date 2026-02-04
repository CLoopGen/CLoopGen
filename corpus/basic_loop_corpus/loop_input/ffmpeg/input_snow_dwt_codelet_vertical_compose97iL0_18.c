#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
int width;
int i;

void init_vars() {
    width = 65536; // Approximately 1MB of data per array (65536 * sizeof(short) = 131072 bytes)

    b0 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int j = 0; j < width; j++) {
        b0[j] = (IDWTELEM)(j % 32);
        b1[j] = (IDWTELEM)((j + 10) % 40);
        b2[j] = (IDWTELEM)((j + 5) % 25);
    }
}