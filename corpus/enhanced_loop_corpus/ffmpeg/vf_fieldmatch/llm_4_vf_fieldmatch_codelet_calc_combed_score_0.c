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
    for (x = 1; x < width - 1; x++) {
        uint8_t v_center = cmkpV[x];
        uint8_t u_center = cmkpU[x];
        int v_active = 0, u_active = 0;

        if (v_center == 255) {
            v_active = 1;
        }
        if (u_center == 255) {
            u_active = 1;
        }

        if (!v_active && !u_active) continue;

        int neighbor_flag = 0;
        if (v_active) {
            neighbor_flag |= (cmkpV[x - 1 - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpV[x     - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpV[x + 1 - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpV[x - 1                ] == 255);
            neighbor_flag |= (cmkpV[x + 1                ] == 255);
            neighbor_flag |= (cmkpV[x - 1 + cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpV[x     + cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpV[x + 1 + cmk_linesizeUV] == 255);
        }
        if (!neighbor_flag && u_active) {
            neighbor_flag |= (cmkpU[x - 1 - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpU[x     - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpU[x + 1 - cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpU[x - 1                ] == 255);
            neighbor_flag |= (cmkpU[x + 1                ] == 255);
            neighbor_flag |= (cmkpU[x - 1 + cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpU[x     + cmk_linesizeUV] == 255);
            neighbor_flag |= (cmkpU[x + 1 + cmk_linesizeUV] == 255);
        }

        if (neighbor_flag) {
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
