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
int step = 2;
for (i = 0; i < num_colors; i += step) {
    for (int j = 0; j < step && (i + j) < num_colors; ++j) {
        int idx = i + j;
        if (rm[idx] >> 6 == ir && gm[idx] >> 6 == ig && bm[idx] >> 6 == ib)
            continue;
        dist = 0;
        tmp = (red - rm[idx]) > 0 ? (red - rm[idx]) : (rm[idx] > (red + 63) ? rm[idx] - (red + 63) : 0);
        dist += tmp * tmp;
        tmp = (green - gm[idx]) > 0 ? (green - gm[idx]) : (gm[idx] > (green + 63) ? gm[idx] - (green + 63) : 0);
        dist += tmp * tmp;
        tmp = (blue - bm[idx]) > 0 ? (blue - bm[idx]) : (bm[idx] > (blue + 63) ? bm[idx] - (blue + 63) : 0);
        dist += tmp * tmp;
        if (dist < mindist) {
            ptr->entries[ptr->num_ents][0] = idx;
            ptr->entries[ptr->num_ents][1] = dist;
            ++ptr->num_ents;
        }
    }
}
}
