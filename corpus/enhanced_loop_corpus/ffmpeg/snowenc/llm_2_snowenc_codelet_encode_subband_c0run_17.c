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

extern SubBand *b;
extern  IDWTELEM *src;
extern  IDWTELEM *parent;
extern int stride;
extern  int w;
extern  int h;
extern int x;
extern int y;
extern int run;
extern int *runs;
extern int run_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with prefetching and linear indexing
    IDWTELEM *src_line = src;
    for (y = 0; y < h; y++) {
        const int y_stride = y * stride;
        for (x = 0; x < w; x++) {
            int v, p = 0;
            int l = 0, lt = 0, t = 0, rt = 0;
            int idx = x + y_stride;
            v = src[idx];
            if (y) {
                int prev_y_stride = (y - 1) * stride;
                t = src[x + prev_y_stride];
                if (x) {
                    lt = src[(x - 1) + prev_y_stride];
                }
                if (x + 1 < w) {
                    rt = src[(x + 1) + prev_y_stride];
                }
            }
            if (x) {
                l = src[(x - 1) + y_stride];
            }
            if (parent) {
                int px = x >> 1;
                int py = y >> 1;
                if (px < b->parent->width && py < b->parent->height)
                    p = parent[px + py * (2 * stride)];
            }
            if (!(l | lt | t | rt | p)) {
                if (v) {
                    runs[run_index++] = run;
                    run = 0;
                } else {
                    run++;
                }
            }
        }
        src_line += stride; // Maintain base pointer update (though not used directly)
    }
}
