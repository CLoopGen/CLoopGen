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
    int idx = i;
    if (rm[idx] >> (8 - 2) != ir || gm[idx] >> (8 - 2) != ig || bm[idx] >> (8 - 2) != ib)
        continue;
    ptr->entries[ptr->num_ents][0] = idx;
    ptr->entries[ptr->num_ents][1] = 0;
    ++ptr->num_ents;
    tmp = rm[idx] - red;
    if (tmp < (256 / (1L << 2) / 2))
        tmp = 256 / (1L << 2) - 1 - tmp;
    dist = tmp * tmp;
    tmp = gm[idx] - green;
    if (tmp < (256 / (1L << 2) / 2))
        tmp = 256 / (1L << 2) - 1 - tmp;
    dist += tmp * tmp;
    tmp = bm[idx] - blue;
    if (tmp < (256 / (1L << 2) / 2))
        tmp = 256 / (1L << 2) - 1 - tmp;
    dist += tmp * tmp;
    if (dist < mindist)
        mindist = dist;
}
}
