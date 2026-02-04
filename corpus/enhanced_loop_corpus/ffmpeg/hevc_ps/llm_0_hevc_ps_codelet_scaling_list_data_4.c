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
    for (int j = 0; j < 4; j++) {
        for (i = 0; i < 64; i++) {
            switch (j) {
                case 0:
                    sl->sl[3][1][i] = sl->sl[2][1][i];
                    break;
                case 1:
                    sl->sl[3][2][i] = sl->sl[2][2][i];
                    break;
                case 2:
                    sl->sl[3][4][i] = sl->sl[2][4][i];
                    break;
                case 3:
                    sl->sl[3][5][i] = sl->sl[2][5][i];
                    break;
            }
        }
    }
}
