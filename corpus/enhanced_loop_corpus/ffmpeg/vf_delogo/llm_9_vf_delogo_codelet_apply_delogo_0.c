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
for (y = logo_y1 + 1; y < logo_y2; y++) {
    uint64_t base_weight_den = (y - logo_y1) * (logo_y2 - y);
    left_sample = topleft[src_linesize * (y - logo_y1)] + topleft[src_linesize * (y - logo_y1 - 1)] + topleft[src_linesize * (y - logo_y1 + 1)];
    right_sample = topright[src_linesize * (y - logo_y1)] + topright[src_linesize * (y - logo_y1 - 1)] + topright[src_linesize * (y - logo_y1 + 1)];
    for (x = logo_x1 + 1, xdst = dst + logo_x1 + 1, xsrc = src + logo_x1 + 1; x < logo_x2; x++, xdst++, xsrc++) {
        if (show && (y == logo_y1 + 1 || y == logo_y2 - 1 || x == logo_x1 + 1 || x == logo_x2 - 1)) {
            *xdst = 0;
            continue;
        }
        uint64_t horiz_weight = (x - logo_x1) * (logo_x2 - x);
        weightl = (uint64_t)(logo_x2 - x) * base_weight_den * sar.den;
        weightr = (uint64_t)(x - logo_x1) * base_weight_den * sar.den;
        weightt = horiz_weight * (logo_y2 - y) * sar.num;
        weightb = horiz_weight * (y - logo_y1) * sar.num;
        unsigned int top_neighbors = topleft[x - logo_x1] + topleft[x - logo_x1 - 1] + topleft[x - logo_x1 + 1];
        unsigned int bot_neighbors = botleft[x - logo_x1] + botleft[x - logo_x1 - 1] + botleft[x - logo_x1 + 1];
        interp = left_sample * weightl + right_sample * weightr + top_neighbors * weightt + bot_neighbors * weightb;
        weight = (weightl + weightr + weightt + weightb) * 3U;
        interp = (interp + (weight >> 1)) / weight;
        if (y >= logo_y + band && y < logo_y + logo_h - band && x >= logo_x + band && x < logo_x + logo_w - band) {
            *xdst = (uint8_t)interp;
        } else {
            unsigned int dist = 0;
            int dx = 0, dy = 0;
            if (x < logo_x + band)
                dx = logo_x + band - x;
            else if (x >= logo_x + logo_w - band)
                dx = x - (logo_x + logo_w - 1 - band);
            if (y < logo_y + band)
                dy = logo_y + band - y;
            else if (y >= logo_y + logo_h - band)
                dy = y - (logo_y + logo_h - 1 - band);
            dist = (dx > dy) ? dx : dy;
            dist = (dist < band) ? dist : band;
            *xdst = (uint8_t)((*xsrc * dist + interp * (band - dist)) / band);
        }
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
