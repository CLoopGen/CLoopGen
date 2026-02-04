#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

typedef unsigned short uint16;

extern int red;
extern int green;
extern int blue;
extern int ir;
extern int ig;
extern int ib;
extern int i;
extern C_cell *ptr;
extern int mindist;
extern int tmp;
extern int dist;
extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int num_colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num_colors; ++i) {
    int skip = 0;
    if (rm[i] >> (8 - 2) == ir && gm[i] >> (8 - 2) == ig && bm[i] >> (8 - 2) == ib) {
        skip = 1;
    }
    if (!skip) {
        dist = 0;
        int diff_r = red - rm[i];
        int upper_bound_r = red + 256 / (1L << 2) - 1;
        if (diff_r > 0) {
            dist += diff_r * diff_r;
        } else {
            int overflow_r = rm[i] - upper_bound_r;
            if (overflow_r > 0) {
                dist += overflow_r * overflow_r;
            }
        }
        int diff_g = green - gm[i];
        int upper_bound_g = green + 256 / (1L << 2) - 1;
        if (diff_g > 0) {
            dist += diff_g * diff_g;
        } else {
            int overflow_g = gm[i] - upper_bound_g;
            if (overflow_g > 0) {
                dist += overflow_g * overflow_g;
            }
        }
        int diff_b = blue - bm[i];
        int upper_bound_b = blue + 256 / (1L << 2) - 1;
        if (diff_b > 0) {
            dist += diff_b * diff_b;
        } else {
            int overflow_b = bm[i] - upper_bound_b;
            if (overflow_b > 0) {
                dist += overflow_b * overflow_b;
            }
        }
        if (dist < mindist) {
            ptr->entries[ptr->num_ents][0] = i;
            ptr->entries[ptr->num_ents][1] = dist;
            ++ptr->num_ents;
        }
    }
}
}
