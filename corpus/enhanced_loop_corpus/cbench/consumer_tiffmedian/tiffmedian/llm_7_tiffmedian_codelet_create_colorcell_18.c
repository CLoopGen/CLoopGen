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
    int i_prev = -1;
    int dist_prev = mindist;
    int cascade = 0;

    for (i = 0; i < num_colors; ++i) {
        int skip = 0;
        if (rm[i] >> (8 - 2) == ir && gm[i] >> (8 - 2) == ig && bm[i] >> (8 - 2) == ib)
            skip = 1;

        dist = 0;
        if (!skip) {
            if ((tmp = red - rm[i]) > 0 || (tmp = rm[i] - (red + 256 / (1L << 2) - 1)) > 0)
                dist += tmp * tmp;
            if ((tmp = green - gm[i]) > 0 || (tmp = gm[i] - (green + 256 / (1L << 2) - 1)) > 0)
                dist += tmp * tmp;
            if ((tmp = blue - bm[i]) > 0 || (tmp = bm[i] - (blue + 256 / (1L << 2) - 1)) > 0)
                dist += tmp * tmp;
        }

        if (dist < mindist && !skip) {
            int idx = ptr->num_ents;
            ptr->entries[idx][0] = i;
            ptr->entries[idx][1] = dist;

            if (i_prev != -1 && (i - i_prev) == 1 && (dist - dist_prev) < 10) {
                cascade++;
            }
            i_prev = i;
            dist_prev = dist;

            ptr->num_ents = idx + 1 + (cascade > 5 ? 1 : 0);
            if (cascade > 5) cascade = 0;
        }
    }
}
