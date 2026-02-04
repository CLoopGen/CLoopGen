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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int v, p = 0;
        int l = 0, lt = 0, t = 0, rt = 0;
        v = src[x + y * stride];
        if (y) {
            t = src[x + (y - 1) * stride];
            if (x) {
                lt = src[x - 1 + (y - 1) * stride];
            }
            if (x + 1 < w) {
                rt = src[x + 1 + (y - 1) * stride];
            }
        }
        if (x) {
            l = src[x - 1 + y * stride];
        }
        if (parent && (x & 1) == 0 && (y & 1) == 0) {
            int px = x >> 1;
            int py = y >> 1;
            if (px < b->parent->width && py < b->parent->height)
                p = parent[px + py * 2 * stride];
        }
        if (!(l | lt | t | rt | p) && v == 0) {
            run++;
        } else if (!(l | lt | t | rt | p)) {
            runs[run_index++] = run;
            run = 0;
        }
    }
}
}
