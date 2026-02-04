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
for (y = 2; y < height - 2; y++) {
    cmkpp += cmk_linesize;
    cmkp += cmk_linesize;
    cmkpn += cmk_linesize;
    cmkpnn += cmk_linesize;
    cmkpV += cmk_linesizeUV;
    cmkpU += cmk_linesizeUV;
    for (x = 2; x < width - 2; x++) {
        int found = 0;
        for (int dy = -1; dy <= 1 && !found; dy++) {
            for (int dx = -1; dx <= 1 && !found; dx++) {
                if (dx == 0 && dy == 0) continue;
                if ((cmkpV[x] == 255 && cmkpV[x + dx + dy * cmk_linesizeUV] == 255) ||
                    (cmkpU[x] == 255 && cmkpU[x + dx + dy * cmk_linesizeUV] == 255)) {
                    found = 1;
                }
            }
        }
        if (found) {
            ((uint16_t *)cmkp)[x] = 65535;
            ((uint16_t *)cmkpn)[x] = 65535;
            if (y & 1)
                ((uint16_t *)cmkpp)[x] = 65535;
            else
                ((uint16_t *)cmkpnn)[x] = 65535;
        }
    }
}
}
