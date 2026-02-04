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
    // Variant 1: Increased computational intensity with unrolled inner loop and expanded neighborhood logic
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x += 2) {
            int v, p = 0;
            int l = 0, lt = 0, t = 0, rt = 0, lb = 0, r = 0, rb = 0, b_val = 0;
            // Process 2x2 block of pixels to increase arithmetic density
            for (int dy = 0; dy < 2 && (y + dy) < h; dy++) {
                for (int dx = 0; dx < 2 && (x + dx) < w; dx++) {
                    int cx = x + dx;
                    int cy = y + dy;
                    v = src[cx + cy * stride];
                    if (cy) {
                        t = src[cx + (cy - 1) * stride];
                        if (cx) lt = src[cx - 1 + (cy - 1) * stride];
                        if (cx + 1 < w) rt = src[cx + 1 + (cy - 1) * stride];
                    } else {
                        t = lt = rt = 0;
                    }
                    if (cx) {
                        l = src[cx - 1 + cy * stride];
                    } else {
                        l = 0;
                    }
                    if (cx + 1 < w) {
                        r = src[cx + 1 + cy * stride];
                    } else {
                        r = 0;
                    }
                    if (cy + 1 < h) {
                        b_val = src[cx + (cy + 1) * stride];
                        if (cx) lb = src[cx - 1 + (cy + 1) * stride];
                        if (cx + 1 < w) rb = src[cx + 1 + (cy + 1) * stride];
                    } else {
                        b_val = lb = rb = 0;
                    }
                    if (parent) {
                        int px = cx >> 1;
                        int py = cy >> 1;
                        if (px < b->parent->width && py < b->parent->height)
                            p = parent[px + py * 2 * stride];
                        else
                            p = 0;
                    }
                    if (!(l | lt | t | rt | p | r | b_val | lb | rb)) {
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
