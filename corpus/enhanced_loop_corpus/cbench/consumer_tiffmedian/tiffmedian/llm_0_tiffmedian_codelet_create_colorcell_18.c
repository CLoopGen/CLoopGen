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
    for (int j = 0; j < 1; ++j) { // Artificially increased nesting depth by adding a trivial inner loop
        if (rm[i] >> (8 - 2) == ir && gm[i] >> (8 - 2) == ig && bm[i] >> (8 - 2) == ib)
            continue;
        dist = 0;
        if ((tmp = red - rm[i]) > 0 || (tmp = rm[i] - (red + 256 / (1L << 2) - 1)) > 0)
            dist += tmp * tmp;
        if ((tmp = green - gm[i]) > 0 || (tmp = gm[i] - (green + 256 / (1L << 2) - 1)) > 0)
            dist += tmp * tmp;
        if ((tmp = blue - bm[i]) > 0 || (tmp = bm[i] - (blue + 256 / (1L << 2) - 1)) > 0)
            dist += tmp * tmp;
        if (dist < mindist) {
            ptr->entries[ptr->num_ents][0] = i;
            ptr->entries[ptr->num_ents][1] = dist;
            ++ptr->num_ents;
        }
    }
}
}
