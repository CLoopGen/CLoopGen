#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

extern int w;
extern int pw;
extern int ph;
extern Jpeg2000TgtNode *t;
extern Jpeg2000TgtNode *t2;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < ph; i += 2) {
        Jpeg2000TgtNode *t_row_start = &t[i * pw];
        int i_half = i >> 1;
        int t2_row_offset = i_half * w;
        for (j = 0; j < pw; j += 2) {
            int j_half = j >> 1;
            Jpeg2000TgtNode *parent_node = &t2[t2_row_offset + j_half];
            t_row_start[j].parent = parent_node;
            if (j + 1 < pw) {
                t_row_start[j + 1].parent = parent_node;
            }
            if (i + 1 < ph) {
                t[(i + 1) * pw + j].parent = parent_node;
                if (j + 1 < pw) {
                    t[(i + 1) * pw + j + 1].parent = parent_node;
                }
            }
        }
    }
}
