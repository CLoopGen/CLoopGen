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
int shift_val = 8 - 2;
int scale = 1 << 2;
int offset = 256 / scale;
int threshold = offset / 2;
int max_val = offset - 1;
int r_adj, g_adj, b_adj;
for (i = 0; i < num_colors && ptr->num_ents < 256; ++i) {
    if ((rm[i] >> shift_val) != ir || (gm[i] >> shift_val) != ig || (bm[i] >> shift_val) != ib)
        continue;
    ptr->entries[ptr->num_ents][0] = i;
    ptr->entries[ptr->num_ents][1] = 0;
    ++ptr->num_ents;
    r_adj = rm[i] - red;
    r_adj = (r_adj < threshold) ? max_val - r_adj : r_adj;
    g_adj = gm[i] - green;
    g_adj = (g_adj < threshold) ? max_val - g_adj : g_adj;
    b_adj = bm[i] - blue;
    b_adj = (b_adj < threshold) ? max_val - b_adj : b_adj;
    dist = r_adj * r_adj + g_adj * g_adj + b_adj * b_adj;
    if (dist < mindist)
        mindist = dist;
}
}
