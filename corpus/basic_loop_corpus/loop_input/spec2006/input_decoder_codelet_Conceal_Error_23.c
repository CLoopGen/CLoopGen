#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **inY;
int i;
int j;
int pos_y;
int pos_x;

void init_vars() {
    const int size = 1024 * 1024 / sizeof(unsigned short); // ~1MB of data
    const int dim = size > 256 ? 256 : size; // Use at least 256x256 if possible

    inY = (unsigned short**)calloc(dim, sizeof(unsigned short*));
    for (int y = 0; y < dim; y++) {
        inY[y] = (unsigned short*)calloc(dim, sizeof(unsigned short));
    }

    pos_y = 0;
    pos_x = 0;

    if (dim < 16) {
        pos_y = 0;
        pos_x = 0;
    } else {
        pos_y = dim - 16;
        pos_x = dim - 16;
    }
}