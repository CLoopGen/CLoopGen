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



void loop() {
    // Variant 1: Consecutive memory access with loop unrolling by factor of 2
    // This variant processes two iterations per loop cycle to promote sequential access and reduce branching
    int i;
    for (i = 0; i < num_colors - 1; i += 2) {
        // Process element i
        if (!(rm[i] >> 6 == ir && gm[i] >> 6 == ig && bm[i] >> 6 == ib)) {
            dist = 0;
            tmp = red - rm[i];
            if (tmp > 0 || (tmp = rm[i] - (red + 63)) > 0)
                dist += tmp * tmp;
            tmp = green - gm[i];
            if (tmp > 0 || (tmp = gm[i] - (green + 63)) > 0)
                dist += tmp * tmp;
            tmp = blue - bm[i];
            if (tmp > 0 || (tmp = bm[i] - (blue + 63)) > 0)
                dist += tmp * tmp;
            if (dist < mindist) {
                ptr->entries[ptr->num_ents][0] = i;
                ptr->entries[ptr->num_ents][1] = dist;
                ++ptr->num_ents;
            }
        }

        // Process element i+1
        if (!(rm[i+1] >> 6 == ir && gm[i+1] >> 6 == ig && bm[i+1] >> 6 == ib)) {
            dist = 0;
            tmp = red - rm[i+1];
            if (tmp > 0 || (tmp = rm[i+1] - (red + 63)) > 0)
                dist += tmp * tmp;
            tmp = green - gm[i+1];
            if (tmp > 0 || (tmp = gm[i+1] - (green + 63)) > 0)
                dist += tmp * tmp;
            tmp = blue - bm[i+1];
            if (tmp > 0 || (tmp = bm[i+1] - (blue + 63)) > 0)
                dist += tmp * tmp;
            if (dist < mindist) {
                ptr->entries[ptr->num_ents][0] = i+1;
                ptr->entries[ptr->num_ents][1] = dist;
                ++ptr->num_ents;
            }
        }
    }

    // Handle remaining element if num_colors is odd
    if (i < num_colors) {
        if (!(rm[i] >> 6 == ir && gm[i] >> 6 == ig && bm[i] >> 6 == ib)) {
            dist = 0;
            tmp = red - rm[i];
            if (tmp > 0 || (tmp = rm[i] - (red + 63)) > 0)
                dist += tmp * tmp;
            tmp = green - gm[i];
            if (tmp > 0 || (tmp = gm[i] - (green + 63)) > 0)
                dist += tmp * tmp;
            tmp = blue - bm[i];
            if (tmp > 0 || (tmp = bm[i] - (blue + 63)) > 0)
                dist += tmp * tmp;
            if (dist < mindist) {
                ptr->entries[ptr->num_ents][0] = i;
                ptr->entries[ptr->num_ents][1] = dist;
                ++ptr->num_ents;
            }
        }
    }
}
