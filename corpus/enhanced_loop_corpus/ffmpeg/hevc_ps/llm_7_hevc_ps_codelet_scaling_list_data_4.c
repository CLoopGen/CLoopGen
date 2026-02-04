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
        uint8_t val1 = sl->sl[2][1][i];
        uint8_t val2 = sl->sl[2][2][i];
        uint8_t val3 = sl->sl[2][4][i];
        uint8_t val4 = sl->sl[2][5][i];

        sl->sl[3][1][i] = val1;
        sl->sl[3][1][i] += 1; // WAW dependency introduced on sl->sl[3][1][i]
        sl->sl[3][1][i] -= 1;

        sl->sl[3][2][i] = val2;
        sl->sl[3][2][i] ^= 0xFF; // Introduce WAR-like pattern via temporary overwrite
        sl->sl[3][2][i] ^= 0xFF; // Restore, creating intra-iteration dependency

        sl->sl[3][4][i] = val3;
        // Create artificial RAW dependency: use previous iteration's value
        if (i > 0) {
            sl->sl[3][4][i] += sl->sl[3][4][i-1]; // Loop-carried RAW dependency
        }

        sl->sl[3][5][i] = val4;
    }
}
