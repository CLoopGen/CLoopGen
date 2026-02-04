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
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x += 2) {
            for (int dy = 0; dy < 2 && (y + dy) < h; dy++) {
                for (int dx = 0; dx < 2 && (x + dx) < w; dx++) {
                    int cur_y = y + dy;
                    int cur_x = x + dx;
                    int v, p = 0;
                    int l = 0, lt = 0, t = 0, rt = 0;
                    v = src[cur_x + cur_y * stride];
                    if (cur_y) {
                        t = src[cur_x + (cur_y - 1) * stride];
                        if (cur_x) {
                            lt = src[cur_x - 1 + (cur_y - 1) * stride];
                        }
                        if (cur_x + 1 < w) {
                            rt = src[cur_x + 1 + (cur_y - 1) * stride];
                        }
                    }
                    if (cur_x) {
                        l = src[cur_x - 1 + cur_y * stride];
                    }
                    if (parent) {
                        int px = cur_x >> 1;
                        int py = cur_y >> 1;
                        if (px < b->parent->width && py < b->parent->height)
                            p = parent[px + py * 2 * stride];
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
            }
        }
    }
}
