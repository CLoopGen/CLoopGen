#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern uint8_t *cmkp;
extern uint8_t *cmkpU;
extern uint8_t *cmkpV;
extern  int width;
extern  int height;
extern  int cmk_linesize;
extern  int cmk_linesizeUV;
extern uint8_t *cmkpp;
extern uint8_t *cmkpn;
extern uint8_t *cmkpnn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < height - 1; y++) {
    cmkpp += cmk_linesize;
    cmkp += cmk_linesize;
    cmkpn += cmk_linesize;
    cmkpnn += cmk_linesize;
    cmkpV += cmk_linesizeUV;
    cmkpU += cmk_linesizeUV;
    int process_row = (y % 3 != 0); // Skip every third row
    if (!process_row) continue;

    for (x = 1; x < width - 1; x++) {
        // Reduce condition complexity: Only check direct neighbors (cross-shaped)
        int trigger = 0;

        if (cmkpV[x] == 255) {
            trigger |= (cmkpV[x - cmk_linesizeUV] == 255); // top
            trigger |= (cmkpV[x + cmk_linesizeUV] == 255); // bottom
            trigger |= (cmkpV[x - 1] == 255);             // left
            trigger |= (cmkpV[x + 1] == 255);             // right
        }
        if (!trigger && cmkpU[x] == 255) {
            trigger |= (cmkpU[x - cmk_linesizeUV] == 255);
            trigger |= (cmkpU[x + cmk_linesizeUV] == 255);
            trigger |= (cmkpU[x - 1] == 255);
            trigger |= (cmkpU[x + 1] == 255);
        }

        if (trigger) {
            ((uint16_t *)cmkp)[x] = 65535;
            ((uint16_t *)cmkpn)[x] = 65535;
            if (y & 1) {
                ((uint16_t *)cmkpp)[x] = 65535;
            } else {
                ((uint16_t *)cmkpnn)[x] = 65535;
            }
        } else {
            // Additional control path: zero out if not triggered (new behavior)
            ((uint16_t *)cmkp)[x] = 0;
        }
    }
}
}
