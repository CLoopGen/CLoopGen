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
    left_sample = topleft[src_linesize * (y - logo_y1)] + topleft[src_linesize * (y - logo_y1 - 1)] + topleft[src_linesize * (y - logo_y1 + 1)];
    right_sample = topright[src_linesize * (y - logo_y1)] + topright[src_linesize * (y - logo_y1 - 1)] + topright[src_linesize * (y - logo_y1 + 1)];
    for (x = logo_x1 + 1, xdst = dst + logo_x1 + 1, xsrc = src + logo_x1 + 1; x < logo_x2; x++, xdst++, xsrc++) {
        if (show && (y == logo_y1 + 1 || y == logo_y2 - 1 || x == logo_x1 + 1 || x == logo_x2 - 1)) {
            *xdst = 0;
            continue;
        }
        weightl = (uint64_t)(logo_x2 - x) * (y - logo_y1) * (logo_y2 - y) * sar.den;
        weightr = (uint64_t)(x - logo_x1) * (y - logo_y1) * (logo_y2 - y) * sar.den;
        weightt = (uint64_t)(x - logo_x1) * (logo_x2 - x) * (logo_y2 - y) * sar.num;
        weightb = (uint64_t)(x - logo_x1) * (logo_x2 - x) * (y - logo_y1) * sar.num;
        interp = left_sample * weightl + right_sample * weightr + (topleft[x - logo_x1] + topleft[x - logo_x1 - 1] + topleft[x - logo_x1 + 1]) * weightt + (botleft[x - logo_x1] + botleft[x - logo_x1 - 1] + botleft[x - logo_x1 + 1]) * weightb;
        weight = (weightl + weightr + weightt + weightb) * 3U;
        interp = (interp + (weight >> 1)) / weight;
        if (y >= logo_y + band && y < logo_y + logo_h - band && x >= logo_x + band && x < logo_x + logo_w - band) {
            *xdst = interp;
        } else {
            unsigned int dist = 0;
            if (x < logo_x + band)
                dist = ((dist) > (logo_x - x + band) ? (dist) : (logo_x - x + band));
            else if (x >= logo_x + logo_w - band)
                dist = ((dist) > (x - (logo_x + logo_w - 1 - band)) ? (dist) : (x - (logo_x + logo_w - 1 - band)));
            if (y < logo_y + band)
                dist = ((dist) > (logo_y - y + band) ? (dist) : (logo_y - y + band));
            else if (y >= logo_y + logo_h - band)
                dist = ((dist) > (y - (logo_y + logo_h - 1 - band)) ? (dist) : (y - (logo_y + logo_h - 1 - band)));
            *xdst = (*xsrc * dist + interp * (band - dist)) / band;
        }
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
