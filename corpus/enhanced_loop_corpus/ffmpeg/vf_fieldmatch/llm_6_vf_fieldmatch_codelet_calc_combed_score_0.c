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
    uint8_t *cmkpV_local = cmkpV;
    uint8_t *cmkpU_local = cmkpU;
    uint16_t *cmkp_16 = (uint16_t *)cmkp;
    uint16_t *cmkpn_16 = (uint16_t *)cmkpn;
    uint16_t *cmkpp_16 = (uint16_t *)cmkpp;
    uint16_t *cmkpnn_16 = (uint16_t *)cmkpnn;
    for (x = 1; x < width - 1; x++) {
        int v_condition = 0, u_condition = 0;
        // Introduce temporal reuse by preloading and reordering memory accesses to reduce redundant loads
        uint8_t center_v = cmkpV_local[x];
        uint8_t center_u = cmkpU_local[x];

        if (center_v == 255) {
            v_condition = (cmkpV_local[x - 1 - cmk_linesizeUV] == 255) ||
                          (cmkpV_local[x     - cmk_linesizeUV] == 255) ||
                          (cmkpV_local[x + 1 - cmk_linesizeUV] == 255) ||
                          (cmkpV_local[x - 1                ] == 255) ||
                          (cmkpV_local[x + 1                ] == 255) ||
                          (cmkpV_local[x - 1 + cmk_linesizeUV] == 255) ||
                          (cmkpV_local[x     + cmk_linesizeUV] == 255) ||
                          (cmkpV_local[x + 1 + cmk_linesizeUV] == 255);
        }

        if (center_u == 255) {
            u_condition = (cmkpU_local[x - 1 - cmk_linesizeUV] == 255) ||
                          (cmkpU_local[x     - cmk_linesizeUV] == 255) ||
                          (cmkpU_local[x + 1 - cmk_linesizeUV] == 255) ||
                          (cmkpU_local[x - 1                ] == 255) ||
                          (cmkpU_local[x + 1                ] == 255) ||
                          (cmkpU_local[x - 1 + cmk_linesizeUV] == 255) ||
                          (cmkpU_local[x     + cmk_linesizeUV] == 255) ||
                          (cmkpU_local[x + 1 + cmk_linesizeUV] == 255);
        }

        if (v_condition || u_condition) {
            cmkp_16[x] = 65535;
            cmkpn_16[x] = 65535;
            if (y & 1)
                cmkpp_16[x] = 65535;
            else
                cmkpnn_16[x] = 65535;
        }
    }
}
}
