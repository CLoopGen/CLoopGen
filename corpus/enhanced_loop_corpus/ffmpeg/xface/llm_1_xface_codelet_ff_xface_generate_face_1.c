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
    // Flattened loop: single loop replacing nested i,j structure
    for (h = 0; h < 48 * 48; h++) {
        i = h % 48;
        j = h / 48;
        k = 0;
        for (l = i - 2; l <= i + 2; l++) {
            for (m = j - 2; m <= j; m++) {
                if (l <= 0 || (l >= i && m == j))
                    continue;
                if (l < 48 && m > 0)
                    k = 2 * k + src[l + m * 48];
            }
        }

        switch (i) {
          case 1:
            switch (j) {
              case 1:
                dst[h] ^= (g_22[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              case 2:
                dst[h] ^= (g_21[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              default:
                dst[h] ^= (g_20[k >> 3] >> (7 - (k & 7))) & 1;
                break;
            }
            break;
          case 2:
            switch (j) {
              case 1:
                dst[h] ^= (g_12[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              case 2:
                dst[h] ^= (g_11[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              default:
                dst[h] ^= (g_10[k >> 3] >> (7 - (k & 7))) & 1;
                break;
            }
            break;
          case 47:  // 48 - 1
            switch (j) {
              case 1:
                dst[h] ^= (g_42[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              case 2:
                dst[h] ^= (g_41[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              default:
                dst[h] ^= (g_40[k >> 3] >> (7 - (k & 7))) & 1;
                break;
            }
            break;
          case 48:
            switch (j) {
              case 1:
                dst[h] ^= (g_32[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              case 2:
                dst[h] ^= (g_31[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              default:
                dst[h] ^= (g_30[k >> 3] >> (7 - (k & 7))) & 1;
                break;
            }
            break;
          default:
            switch (j) {
              case 1:
                dst[h] ^= (g_02[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              case 2:
                dst[h] ^= (g_01[k >> 3] >> (7 - (k & 7))) & 1;
                break;
              default:
                dst[h] ^= (g_00[k >> 3] >> (7 - (k & 7))) & 1;
                break;
            }
            break;
        }
    }
}
