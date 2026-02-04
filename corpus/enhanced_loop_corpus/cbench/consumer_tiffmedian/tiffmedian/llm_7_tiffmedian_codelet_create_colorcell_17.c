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
    int temp_num_ents = ptr->num_ents;
    for (i = 0; i < num_colors; ++i) {
        int match = 1;
        if (rm[i] >> (8 - 2) != ir) match = 0;
        if (gm[i] >> (8 - 2) != ig) match = 0;
        if (bm[i] >> (8 - 2) != ib) match = 0;
        ptr->entries[temp_num_ents][0] = i & -(match);
        ptr->entries[temp_num_ents][1] = 0 & -(match);
        temp_num_ents += match;
        int tmp = rm[i] - red;
        if (tmp < (256 / (1L << 2) / 2))
            tmp = 256 / (1L << 2) - 1 - tmp;
        int dist = tmp * tmp;
        tmp = gm[i] - green;
        if (tmp < (256 / (1L << 2) / 2))
            tmp = 256 / (1L << 2) - 1 - tmp;
        dist += tmp * tmp;
        tmp = bm[i] - blue;
        if (tmp < (256 / (1L << 2) / 2))
            tmp = 256 / (1L << 2) - 1 - tmp;
        dist += tmp * tmp;
        mindist = (dist < mindist && (rm[i] >> (8-2) == ir && gm[i] >> (8-2) == ig && bm[i] >> (8-2) == ib)) ? dist : mindist;
    }
    ptr->num_ents = temp_num_ents;
}
