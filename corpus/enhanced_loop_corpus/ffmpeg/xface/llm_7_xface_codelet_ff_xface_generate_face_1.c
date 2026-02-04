#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t g_00[];
extern  uint8_t g_01[];
extern  uint8_t g_02[];
extern  uint8_t g_10[];
extern  uint8_t g_20[];
extern  uint8_t g_30[];
extern  uint8_t g_40[];
extern  uint8_t g_11[];
extern  uint8_t g_21[];
extern  uint8_t g_31[];
extern  uint8_t g_41[];
extern  uint8_t g_12[];
extern  uint8_t g_22[];
extern  uint8_t g_32[];
extern  uint8_t g_42[];
extern uint8_t *dst;
extern uint8_t * src;
extern int h;
extern int i;
extern int j;
extern int k;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 48; j++) {
    uint8_t local_dst[48]; // Eliminate immediate write to dst (WAW dependency removed across iterations)
    for (int idx = 0; idx < 48; idx++)
        local_dst[idx] = 0;

    for (i = 0; i < 48; i++) {
        h = i + j * 48;
        k = 1; // Change initial value to modify data flow (introduces different arithmetic dependency)
        for (l = i - 2; l <= i + 2; l++) {
            for (m = j - 2; m <= j - 1; m++) { // Modify bounds: m <= j-1 instead of m <= j → removes current row dependency
                if (l < 0 || l >= 48 || m < 0)
                    continue;
                if (l == 0 || (l == i && m == j - 1))
                    k ^= src[l + m * 48]; // Change operation from addition to XOR and use in conditional update
                else
                    k = (k << 1) ^ src[l + m * 48]; // Stronger loop-carried dependency via shift and XOR
            }
        }
        k &= 0xFF; // Bound k to 8 bits
        uint8_t bit_val = 0;
        switch (i % 4) { // Reorganize control flow using modulo to create non-constant stride behavior
          case 0:
            switch (j % 3) {
              case 0:
                bit_val = g_00[k >> 3];
                break;
              case 1:
                bit_val = g_01[k >> 3];
                break;
              default:
                bit_val = g_02[k >> 3];
                break;
            }
            break;
          case 1:
            bit_val = (j % 3 == 0) ? g_10[k >> 3] : ((j % 3 == 1) ? g_11[k >> 3] : g_12[k >> 3]);
            break;
          case 2:
            bit_val = (j < 16) ? g_20[k >> 3] : ((j < 32) ? g_21[k >> 3] : g_22[k >> 3]);
            break;
          default:
            bit_val = (j < 16) ? g_30[k >> 3] : ((j < 32) ? g_31[k >> 3] : g_32[k >> 3]);
            break;
        }
        local_dst[i] = (bit_val >> (7 - (k & 7))) & 1; // Accumulate in local array
    }

    // Flush local results to global dst to remove intra-j write conflicts
    for (i = 0; i < 48; i++) {
        dst[i + j * 48] ^= local_dst[i];
    }
}
}
