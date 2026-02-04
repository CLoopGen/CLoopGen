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
    int i_local;
    int dist_local;
    int tmp_local;
    int num_ents_local = ptr->num_ents;

    for (i_local = 0; i_local < num_colors; ++i_local) {
        if (rm[i_local] >> (8 - 2) == ir && gm[i_local] >> (8 - 2) == ig && bm[i_local] >> (8 - 2) == ib)
            continue;
        dist_local = 0;
        if ((tmp_local = red - rm[i_local]) > 0 || (tmp_local = rm[i_local] - (red + 256 / (1L << 2) - 1)) > 0)
            dist_local += tmp_local * tmp_local;
        if ((tmp_local = green - gm[i_local]) > 0 || (tmp_local = gm[i_local] - (green + 256 / (1L << 2) - 1)) > 0)
            dist_local += tmp_local * tmp_local;
        if ((tmp_local = blue - bm[i_local]) > 0 || (tmp_local = bm[i_local] - (blue + 256 / (1L << 2) - 1)) > 0)
            dist_local += tmp_local * tmp_local;
        if (dist_local < mindist) {
            ptr->entries[num_ents_local][0] = i_local;
            ptr->entries[num_ents_local][1] = dist_local;
            ++num_ents_local;
        }
    }
    ptr->num_ents = num_ents_local;
}
