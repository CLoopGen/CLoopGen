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
    // Variant 1: Consecutive Memory Access with Local Caching and Strided Step Unrolling
    uint8_t *cmkpV_local = cmkpV + cmk_linesizeUV;
    uint8_t *cmkpU_local = cmkpU + cmk_linesizeUV;
    uint8_t *cmkp_base = cmkp;
    uint8_t *cmkpn_base = cmkpn;
    uint8_t *cmkpp_base = cmkpp;
    uint8_t *cmkpnn_base = cmkpnn;
    
    for (y = 1; y < height - 1; y++) {
        cmkp_base += cmk_linesize;
        cmkpn_base += cmk_linesize;
        cmkpp_base += cmk_linesize;
        cmkpnn_base += cmk_linesize;
        cmkpV_local += cmk_linesizeUV;
        cmkpU_local += cmk_linesizeUV;

        uint16_t *cmkp_16 = (uint16_t *)(cmkp_base);
        uint16_t *cmkpn_16 = (uint16_t *)(cmkpn_base);
        uint16_t *cmkpp_16 = (uint16_t *)(cmkpp_base);
        uint16_t *cmkpnn_16 = (uint16_t *)(cmkpnn_base);

        const uint8_t *cmkpV_prev_row = cmkpV_local - cmk_linesizeUV;
        const uint8_t *cmkpV_curr_row = cmkpV_local;
        const uint8_t *cmkpV_next_row = cmkpV_local + cmk_linesizeUV;
        const uint8_t *cmkpU_prev_row = cmkpU_local - cmk_linesizeUV;
        const uint8_t *cmkpU_curr_row = cmkpU_local;
        const uint8_t *cmkpU_next_row = cmkpU_local + cmk_linesizeUV;

        for (x = 1; x < width - 1; x += 2) {  // Process two pixels at a time
            int x1 = x;
            int x2 = x + 1;

            // Pre-load values to simulate more sequential access pattern
            uint8_t v_center1 = cmkpV_curr_row[x1], v_left1 = cmkpV_curr_row[x1-1], v_right1 = cmkpV_curr_row[x1+1];
            uint8_t v_top_left1 = cmkpV_prev_row[x1-1], v_top1 = cmkpV_prev_row[x1], v_top_right1 = cmkpV_prev_row[x1+1];
            uint8_t v_bot_left1 = cmkpV_next_row[x1-1], v_bot1 = cmkpV_next_row[x1], v_bot_right1 = cmkpV_next_row[x1+1];

            uint8_t u_center1 = cmkpU_curr_row[x1], u_left1 = cmkpU_curr_row[x1-1], u_right1 = cmkpU_curr_row[x1+1];
            uint8_t u_top_left1 = cmkpU_prev_row[x1-1], u_top1 = cmkpU_prev_row[x1], u_top_right1 = cmkpU_prev_row[x1+1];
            uint8_t u_bot_left1 = cmkpU_next_row[x1-1], u_bot1 = cmkpU_next_row[x1], u_bot_right1 = cmkpU_next_row[x1+1];

            int cond1 = (v_center1 == 255) &&
                (v_top_left1 == 255 || v_top1 == 255 || v_top_right1 == 255 ||
                 v_left1 == 255 || v_right1 == 255 ||
                 v_bot_left1 == 255 || v_bot1 == 255 || v_bot_right1 == 255);

            int cond2 = (u_center1 == 255) &&
                (u_top_left1 == 255 || u_top1 == 255 || u_top_right1 == 255 ||
                 u_left1 == 255 || u_right1 == 255 ||
                 u_bot_left1 == 255 || u_bot1 == 255 || u_bot_right1 == 255);

            if (cond1 || cond2) {
                cmkp_16[x1] = 65535;
                cmkpn_16[x1] = 65535;
                if (y & 1)
                    cmkpp_16[x1] = 65535;
                else
                    cmkpnn_16[x1] = 65535;
            }

            if (x2 < width - 1) {
                uint8_t v_center2 = cmkpV_curr_row[x2], v_left2 = cmkpV_curr_row[x2-1], v_right2 = cmkpV_curr_row[x2+1];
                uint8_t v_top_left2 = cmkpV_prev_row[x2-1], v_top2 = cmkpV_prev_row[x2], v_top_right2 = cmkpV_prev_row[x2+1];
                uint8_t v_bot_left2 = cmkpV_next_row[x2-1], v_bot2 = cmkpV_next_row[x2], v_bot_right2 = cmkpV_next_row[x2+1];

                uint8_t u_center2 = cmkpU_curr_row[x2], u_left2 = cmkpU_curr_row[x2-1], u_right2 = cmkpU_curr_row[x2+1];
                uint8_t u_top_left2 = cmkpU_prev_row[x2-1], u_top2 = cmkpU_prev_row[x2], u_top_right2 = cmkpU_prev_row[x2+1];
                uint8_t u_bot_left2 = cmkpU_next_row[x2-1], u_bot2 = cmkpU_next_row[x2], u_bot_right2 = cmkpU_next_row[x2+1];

                int cond1_2 = (v_center2 == 255) &&
                    (v_top_left2 == 255 || v_top2 == 255 || v_top_right2 == 255 ||
                     v_left2 == 255 || v_right2 == 255 ||
                     v_bot_left2 == 255 || v_bot2 == 255 || v_bot_right2 == 255);

                int cond2_2 = (u_center2 == 255) &&
                    (u_top_left2 == 255 || u_top2 == 255 || u_top_right2 == 255 ||
                     u_left2 == 255 || u_right2 == 255 ||
                     u_bot_left2 == 255 || u_bot2 == 255 || u_bot_right2 == 255);

                if (cond1_2 || cond2_2) {
                    cmkp_16[x2] = 65535;
                    cmkpn_16[x2] = 65535;
                    if (y & 1)
                        cmkpp_16[x2] = 65535;
                    else
                        cmkpnn_16[x2] = 65535;
                }
            }
        }
    }
}
