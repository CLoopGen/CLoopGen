#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int t;
extern int mask_id;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_mask_copy[8][4];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            local_mask_copy[i][j] = mask[0][i][j];

    for (y = row_and_7; y < h + row_and_7; y++)
        local_mask_copy[y][mask_id] |= t;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            mask[0][i][j] = local_mask_copy[i][j];
}
