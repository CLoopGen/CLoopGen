#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

extern uint8_t *dst;
extern int dst_linesize;
extern uint8_t *src;
extern int src_linesize;
extern AVRational sar;
extern int logo_x;
extern int logo_y;
extern int logo_w;
extern int logo_h;
extern unsigned int band;
extern int show;
extern int x;
extern int y;
extern uint64_t interp;
extern uint64_t weightl;
extern uint64_t weightr;
extern uint64_t weightt;
extern uint64_t weightb;
extern uint64_t weight;
extern uint8_t *xdst;
extern uint8_t *xsrc;
extern uint8_t *topleft;
extern uint8_t *botleft;
extern uint8_t *topright;
extern unsigned int left_sample;
extern unsigned int right_sample;
extern int logo_x1;
extern int logo_x2;
extern int logo_y1;
extern int logo_y2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int h = logo_y2 - logo_y1;
const int w = logo_x2 - logo_x1;

// Precompute vertical access indices to enable strided memory access pattern
int idx_top[h], idx_bot[h];
for (int i = 0; i < h; i++) {
    idx_top[i] = i * src_linesize;
    idx_bot[i] = (i + 2) * src_linesize; // botleft offset by +2 rows
}

for (y = logo_y1 + 1; y < logo_y2; y++) {
    int sy = y - logo_y1;
    left_sample = topleft[idx_top[sy]] + topleft[idx_top[sy-1]] + topleft[idx_top[sy+1]];
    right_sample = topright[idx_top[sy]] + topright[idx_top[sy-1]] + topright[idx_top[sy+1]];

    // Use strided base pointers with precomputed offsets
    uint8_t *xdst_base = dst + dst_linesize * (y - logo_y1 - 1);
    uint8_t *xsrc_base = src + src_linesize * (y - logo_y1 - 1);
    uint8_t *topleft_scan = topleft + sy;
    uint8_t *botleft_scan = botleft + sy;

    for (x = logo_x1 + 1; x < logo_x2; x++) {
        int sx = x - logo_x1;

        // Strided horizontal access: treat image data as column-major during processing
        if (show && (y == logo_y1 + 1 || y == logo_y2 - 1 || x == logo_x1 + 1 || x == logo_x2 - 1)) {
            xdst_base[x] = 0;
            continue;
        }

        weightl = (uint64_t)(logo_x2 - x) * sy * (logo_y2 - y) * sar.den;
        weightr = (uint64_t)(x - logo_x1) * sy * (logo_y2 - y) * sar.den;
        weightt = (uint64_t)sx * (logo_x2 - x) * (logo_y2 - y) * sar.num;
        weightb = (uint64_t)sx * (logo_x2 - x) * sy * sar.num;

        // Access neighbors using fixed stride and relative column index
        unsigned int top_neighbor = topleft_scan[sx*w] + topleft_scan[(sx-1)*w] + topleft_scan[(sx+1)*w];
        unsigned int bot_neighbor = botleft_scan[sx*w] + botleft_scan[(sx-1)*w] + botleft_scan[(sx+1)*w];

        interp = left_sample * weightl + 
                 right_sample * weightr + 
                 top_neighbor * weightt + 
                 bot_neighbor * weightb;

        weight = (weightl + weightr + weightt + weightb) * 3U;
        interp = (interp + (weight >> 1)) / weight;

        if (y >= logo_y + band && y < logo_y + logo_h - band && x >= logo_x + band && x < logo_x + logo_w - band) {
            xdst_base[x] = interp;
        } else {
            unsigned int dist = 0;
            if (x < logo_x + band)
                dist = (dist > (logo_x - x + band)) ? dist : (logo_x - x + band);
            else if (x >= logo_x + logo_w - band)
                dist = (dist > (x - (logo_x + logo_w - 1 - band))) ? dist : (x - (logo_x + logo_w - 1 - band));
            if (y < logo_y + band)
                dist = (dist > (logo_y - y + band)) ? dist : (logo_y - y + band);
            else if (y >= logo_y + logo_h - band)
                dist = (dist > (y - (logo_y + logo_h - 1 - band))) ? dist : (y - (logo_y + logo_h - 1 - band));
            xdst_base[x] = (xsrc_base[x] * dist + interp * (band - dist)) / band;
        }
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
