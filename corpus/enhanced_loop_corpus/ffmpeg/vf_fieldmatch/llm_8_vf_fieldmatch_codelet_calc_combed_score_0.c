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
for (y = 2; y < height - 2; y += 2) {
    cmkpp += 2 * cmk_linesize;
    cmkp += 2 * cmk_linesize;
    cmkpn += 2 * cmk_linesize;
    cmkpnn += 2 * cmk_linesize;
    cmkpV += 2 * cmk_linesizeUV;
    cmkpU += 2 * cmk_linesizeUV;
    for (x = 2; x < width - 2; x += 2) {
        uint8_t v_center = cmkpV[x];
        uint8_t u_center = cmkpU[x];
        int v_condition = 0, u_condition = 0;

        if (v_center == 255) {
            v_condition = (cmkpV[x - 1 - cmk_linesizeUV] == 255) ||
                          (cmkpV[x     - cmk_linesizeUV] == 255) ||
                          (cmkpV[x + 1 - cmk_linesizeUV] == 255) ||
                          (cmkpV[x - 1                ] == 255) ||
                          (cmkpV[x + 1                ] == 255) ||
                          (cmkpV[x - 1 + cmk_linesizeUV] == 255) ||
                          (cmkpV[x     + cmk_linesizeUV] == 255) ||
                          (cmkpV[x + 1 + cmk_linesizeUV] == 255);
        }

        if (u_center == 255) {
            u_condition = (cmkpU[x - 1 - cmk_linesizeUV] == 255) ||
                          (cmkpU[x     - cmk_linesizeUV] == 255) ||
                          (cmkpU[x + 1 - cmk_linesizeUV] == 255) ||
                          (cmkpU[x - 1                ] == 255) ||
                          (cmkpU[x + 1                ] == 255) ||
                          (cmkpU[x - 1 + cmk_linesizeUV] == 255) ||
                          (cmkpU[x     + cmk_linesizeUV] == 255) ||
                          (cmkpU[x + 1 + cmk_linesizeUV] == 255);
        }

        if (v_condition || u_condition) {
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
