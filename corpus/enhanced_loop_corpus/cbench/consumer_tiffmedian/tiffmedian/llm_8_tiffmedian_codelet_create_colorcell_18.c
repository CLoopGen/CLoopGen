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
for (i = 0; i < num_colors && ptr->num_ents < 256; ++i) {
    if (rm[i] >> (8 - 2) == ir && gm[i] >> (8 - 2) == ig && bm[i] >> (8 - 2) == ib)
        continue;
    dist = 0;
    tmp = red - rm[i];
    if (tmp > 0) dist += tmp * tmp;
    else if ((tmp = rm[i] - (red + 63)) > 0) dist += tmp * tmp;

    tmp = green - gm[i];
    if (tmp > 0) dist += tmp * tmp;
    else if ((tmp = gm[i] - (green + 63)) > 0) dist += tmp * tmp;

    tmp = blue - bm[i];
    if (tmp > 0) dist += tmp * tmp;
    else if ((tmp = bm[i] - (blue + 63)) > 0) dist += tmp * tmp;

    if (dist < mindist) {
        int idx = ptr->num_ents++;
        ptr->entries[idx][0] = i;
        ptr->entries[idx][1] = dist;
    }
}
}
