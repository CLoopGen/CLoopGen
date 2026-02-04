#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

extern ScalingList *sl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int indices[4][2] = {{3,1}, {3,2}, {3,4}, {3,5}};
        int src_indices[4][2] = {{2,1}, {2,2}, {2,4}, {2,5}};
        for (int j = 0; j < 4; j++) {
            sl->sl[indices[j][0]][indices[j][1]][i] = sl->sl[src_indices[j][0]][src_indices[j][1]][i];
        }
    }
}
