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
    if (rm[i] >> (8 - 2) != ir || gm[i] >> (8 - 2) != ig || bm[i] >> (8 - 2) != ib)
        continue;
    ptr->entries[ptr->num_ents][0] = i;
    ptr->entries[ptr->num_ents][1] = 0;
    ++ptr->num_ents;
    int shift_val = 8 - 2;
    int threshold = (256 / (1 << 2)) / 2;
    int max_val = (256 / (1 << 2)) - 1;
    tmp = rm[i] - red;
    if (tmp < threshold)
        tmp = max_val - tmp;
    dist = tmp * tmp;
    tmp = gm[i] - green;
    if (tmp < threshold)
        tmp = max_val - tmp;
    dist += tmp * tmp;
    tmp = bm[i] - blue;
    if (tmp < threshold)
        tmp = max_val - tmp;
    dist += tmp * tmp;
    if (dist < mindist)
        mindist = dist;
}
}
