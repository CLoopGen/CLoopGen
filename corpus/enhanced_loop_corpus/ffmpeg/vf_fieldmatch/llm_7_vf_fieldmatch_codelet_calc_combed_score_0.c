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
// Eliminate loop-carried dependencies by unrolling the inner loop twice and using temporary write-back buffer
// This introduces WAW and WAR dependencies artificially via speculative writes but resolves them at end of block
for (y = 1; y < height - 1; y++) {
    cmkpp += cmk_linesize;
    cmkp += cmk_linesize;
    cmkpn += cmk_linesize;
    cmkpnn += cmk_linesize;
    cmkpV += cmk_linesizeUV;
    cmkpU += cmk_linesizeUV;

    uint16_t temp_write_cmkp[width];     // Local buffers to break RAW/WAW across iterations
    uint16_t temp_write_cmkpn[width];
    uint16_t temp_write_others[width];

    // Initialize only needed range
    for (int i = 1; i < width - 1; i++) {
        temp_write_cmkp[i] = ((uint16_t*)cmkp)[i];
        temp_write_cmkpn[i] = ((uint16_t*)cmkpn)[i];
        temp_write_others[i] = (y & 1) ? ((uint16_t*)cmkpp)[i] : ((uint16_t*)cmkpnn)[i];
    }

    // Unroll inner loop by 2 to expose more ILP and modify data dependency chains
    for (x = 1; x < width - 1; x += 2) {
        int update_pair = 0;

        // Process two pixels at once — introduces intra-loop parallelism and changes RAW pattern
        int v_cond_x = (cmkpV[x] == 255) &&
            (cmkpV[x - 1 - cmk_linesizeUV] == 255 || cmkpV[x - cmk_linesizeUV] == 255 ||
             cmkpV[x + 1 - cmk_linesizeUV] == 255 || cmkpV[x - 1] == 255 ||
             cmkpV[x + 1] == 255 || cmkpV[x - 1 + cmk_linesizeUV] == 255 ||
             cmkpV[x + cmk_linesizeUV] == 255 || cmkpV[x + 1 + cmk_linesizeUV] == 255);

        int u_cond_x = (cmkpU[x] == 255) &&
            (cmkpU[x - 1 - cmk_linesizeUV] == 255 || cmkpU[x - cmk_linesizeUV] == 255 ||
             cmkpU[x + 1 - cmk_linesizeUV] == 255 || cmkpU[x - 1] == 255 ||
             cmkpU[x + 1] == 255 || cmkpU[x - 1 + cmk_linesizeUV] == 255 ||
             cmkpU[x + cmk_linesizeUV] == 255 || cmkpU[x + 1 + cmk_linesizeUV] == 255);

        int v_cond_x1 = (x+1 < width - 1) ? ((cmkpV[x+1] == 255) &&
            (cmkpV[x   - cmk_linesizeUV] == 255 || cmkpV[x+1 - cmk_linesizeUV] == 255 ||
             cmkpV[x+2 - cmk_linesizeUV] == 255 || cmkpV[x    ] == 255 ||
             cmkpV[x+2] == 255 || cmkpV[x   + cmk_linesizeUV] == 255 ||
             cmkpV[x+1 + cmk_linesizeUV] == 255 || cmkpV[x+2 + cmk_linesizeUV] == 255)) : 0;

        int u_cond_x1 = (x+1 < width - 1) ? ((cmkpU[x+1] == 255) &&
            (cmkpU[x   - cmk_linesizeUV] == 255 || cmkpU[x+1 - cmk_linesizeUV] == 255 ||
             cmkpU[x+2 - cmk_linesizeUV] == 255 || cmkpU[x    ] == 255 ||
             cmkpU[x+2] == 255 || cmkpU[x   + cmk_linesizeUV] == 255 ||
             cmkpU[x+1 + cmk_linesizeUV] == 255 || cmkpU[x+2 + cmk_linesizeUV] == 255)) : 0;

        if (v_cond_x || u_cond_x) {
            temp_write_cmkp[x] = 65535;
            temp_write_cmkpn[x] = 65535;
            temp_write_others[x] = 65535;
            update_pair = 1;
        }
        if (v_cond_x1 || u_cond_x1) {
            temp_write_cmkp[x+1] = 65535;
            temp_write_cmkpn[x+1] = 65535;
            temp_write_others[x+1] = 65535;
            update_pair = 1;
        }
    }

    // Final write-back to break all intermediate memory dependencies (WAW removed during computation)
    for (x = 1; x < width - 1; x++) {
        ((uint16_t*)cmkp)[x] = temp_write_cmkp[x];
        ((uint16_t*)cmkpn)[x] = temp_write_cmkpn[x];
        if (y & 1)
            ((uint16_t*)cmkpp)[x] = temp_write_others[x];
        else
            ((uint16_t*)cmkpnn)[x] = temp_write_others[x];
    }
}
}
