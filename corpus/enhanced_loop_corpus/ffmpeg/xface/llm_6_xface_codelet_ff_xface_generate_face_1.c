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
    for (i = 0; i < 48; i++) {
        h = i + j * 48;
        k = 0;
        uint8_t temp_val = 0;
        for (l = i - 2; l <= i + 2; l++) {
            for (m = j - 2; m <= j; m++) {
                if (l <= 0 || (l >= i && m == j))
                    continue;
                if (l < 48 && m > 0)
                    temp_val = 2 * temp_val + src[l + m * 48]; // Introduce temporary to delay write to k
            }
        }
        k = temp_val; // Break WAW and RAW dependency on k by deferring assignment
        uint8_t index_shift = k >> 3;
        uint8_t bit_pos = 7 - (k & 7);
        switch (i) {
          case 1:
            switch (j) {
              case 1:
                dst[h] ^= (g_22[index_shift] >> bit_pos) & 1;
                break;
              case 2:
                dst[h] ^= (g_21[index_shift] >> bit_pos) & 1;
                break;
              default:
                dst[h] ^= (g_20[index_shift] >> bit_pos) & 1;
                break;
            }
            break;
          case 2:
            switch (j) {
              case 1:
                dst[h] ^= (g_12[index_shift] >> bit_pos) & 1;
                break;
              case 2:
                dst[h] ^= (g_11[index_shift] >> bit_pos) & 1;
                break;
              default:
                dst[h] ^= (g_10[index_shift] >> bit_pos) & 1;
                break;
            }
            break;
          case 47: // Fixed: 48-1 is 47, not left as expression
            switch (j) {
              case 1:
                dst[h] ^= (g_42[index_shift] >> bit_pos) & 1;
                break;
              case 2:
                dst[h] ^= (g_41[index_shift] >> bit_pos) & 1;
                break;
              default:
                dst[h] ^= (g_40[index_shift] >> bit_pos) & 1;
                break;
            }
            break;
          case 48:
            switch (j) {
              case 1:
                dst[h] ^= (g_32[index_shift] >> bit_pos) & 1;
                break;
              case 2:
                dst[h] ^= (g_31[index_shift] >> bit_pos) & 1;
                break;
              default:
                dst[h] ^= (g_30[index_shift] >> bit_pos) & 1;
                break;
            }
            break;
          default:
            switch (j) {
              case 1:
                dst[h] ^= (g_02[index_shift] >> bit_pos) & 1;
                break;
              case 2:
                dst[h] ^= (g_01[index_shift] >> bit_pos) & 1;
                break;
              default:
                dst[h] ^= (g_00[index_shift] >> bit_pos) & 1;
                break;
            }
            break;
        }
    }
}
}
