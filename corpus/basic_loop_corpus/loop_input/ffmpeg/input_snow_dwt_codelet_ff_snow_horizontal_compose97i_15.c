#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int width;
int x;

void init_vars() {
    width = 65536; 

    b = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));
    temp = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int i = 0; i < width; i++) {
        temp[i] = (IDWTELEM)(i & 255);
        b[i] = 0;
    }

    for (int i = 0; i < 2; i++) {
        b[i] = (IDWTELEM)(i & 127);
    }
}