#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;
typedef short IDWTELEM;

typedef struct x_and_coeff {
    int16_t x;
    uint16_t coeff;
} x_and_coeff;

typedef struct SubBand {
    int level;
    int stride;
    int width;
    int height;
    int qlog;
    DWTELEM *buf;
    IDWTELEM *ibuf;
    int buf_x_offset;
    int buf_y_offset;
    int stride_line;
    x_and_coeff *x_coeff;
    struct SubBand *parent;
    uint8_t state[519][32];
} SubBand;

SubBand *b;
IDWTELEM *src;
IDWTELEM *parent;
int stride;
int w;
int h;
int x;
int y;
int run;
int *runs;
int run_index;

void init_vars() {
    // Allocate b and initialize its parent
    b = (SubBand*)calloc(1, sizeof(SubBand));
    b->parent = (SubBand*)calloc(1, sizeof(SubBand));

    // Set reasonable dimensions: aim for ~64MB of data in src
    w = 4096;
    h = 4096;
    stride = w;  // stride equals width

    // Allocate src: array of IDWTELEM (short), size w * h
    src = (IDWTELEM*)calloc(w * h, sizeof(IDWTELEM));

    // Allocate parent buffer: half resolution in each dimension, but stride is 2*stride of src
    parent = (IDWTELEM*)calloc((w / 2 + 1) * (h / 2 + 1), sizeof(IDWTELEM));
    
    // Initialize b->parent dimensions
    b->parent->width = w / 2 + 1;
    b->parent->height = h / 2 + 1;

    // Allocate runs array: worst-case scenario, each pixel could be non-zero
    runs = (int*)malloc(w * h * sizeof(int));
    run_index = 0;
    run = 0;

    // Initialize some sample data to avoid all zeros (ensure meaningful execution)
    for (int i = 0; i < w * h; i++) {
        src[i] = rand() % 3 - 1;  // -1, 0, or 1
    }
    for (int i = 0; i < (w / 2 + 1) * (h / 2 + 1); i++) {
        parent[i] = rand() % 3 - 1;
    }
}