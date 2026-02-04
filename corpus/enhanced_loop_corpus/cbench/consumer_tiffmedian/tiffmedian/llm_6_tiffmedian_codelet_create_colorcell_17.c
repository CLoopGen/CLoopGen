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
    int dist_local = mindist;
    for (i_local = 0; i_local < num_colors; ++i_local) {
        if (rm[i_local] >> (8 - 2) != ir || gm[i_local] >> (8 - 2) != ig || bm[i_local] >> (8 - 2) != ib)
            continue;
        ptr->entries[ptr->num_ents][0] = i_local;
        ptr->entries[ptr->num_ents][1] = 0;
        ++ptr->num_ents;
        int tmp_r = rm[i_local] - red;
        if (tmp_r < (256 / (1L << 2) / 2))
            tmp_r = 256 / (1L << 2) - 1 - tmp_r;
        int tmp_g = gm[i_local] - green;
        if (tmp_g < (256 / (1L << 2) / 2))
            tmp_g = 256 / (1L << 2) - 1 - tmp_g;
        int tmp_b = bm[i_local] - blue;
        if (tmp_b < (256 / (1L << 2) / 2))
            tmp_b = 256 / (1L << 2) - 1 - tmp_b;
        int dist_candidate = tmp_r * tmp_r + tmp_g * tmp_g + tmp_b * tmp_b;
        if (dist_candidate < dist_local)
            dist_local = dist_candidate;
    }
    mindist = dist_local;
}
