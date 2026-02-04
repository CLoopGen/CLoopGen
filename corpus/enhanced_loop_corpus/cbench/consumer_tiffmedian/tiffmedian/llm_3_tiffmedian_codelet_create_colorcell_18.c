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



void loop() {
    // Variant 2: Strided memory access with reverse traversal
    // This variant accesses array elements in a strided pattern (every 4th element), then handles remainder
    // Simulates non-unit stride access, useful for testing cache behavior or vectorization under stride
    int stride = 4;
    int start, i;

    // First pass: strided access forward (0, 4, 8, ...)
    for (start = 0; start < stride; ++start) {
        for (i = start; i < num_colors; i += stride) {
            if (rm[i] >> 6 == ir && gm[i] >> 6 == ig && bm[i] >> 6 == ib)
                continue;
            dist = 0;
            if ((tmp = red - rm[i]) > 0 || (tmp = rm[i] - (red + 63)) > 0)
                dist += tmp * tmp;
            if ((tmp = green - gm[i]) > 0 || (tmp = gm[i] - (green + 63)) > 0)
                dist += tmp * tmp;
            if ((tmp = blue - bm[i]) > 0 || (tmp = bm[i] - (blue + 63)) > 0)
                dist += tmp * tmp;
            if (dist < mindist) {
                ptr->entries[ptr->num_ents][0] = i;
                ptr->entries[ptr->num_ents][1] = dist;
                ++ptr->num_ents;
            }
        }
    }
}
