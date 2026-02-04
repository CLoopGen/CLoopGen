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



void loop() {
    for (j = 0; j < 48; j++) {
        for (i = 0; i < 48; i++) {
            h = i + j * 48;
            k = 0;
            for (l = i - 2; l <= i + 2; l++) {
                for (m = j - 2; m <= j; m++) {
                    if (l <= 0 || (l >= i && m == j))
                        continue;
                    if (l < 48 && m > 0) {
                        int index = l + (m << 6); // Strided access: use bit shift to simulate stride of 64
                        k = (k << 1) | (src[index] & 1);
                    }
                }
            }
            int bit_index = k >> 3;
            int bit_shift = 7 - (k & 7);
            switch (i) {
              case 1:
                dst[h] ^= (j == 1 ? (g_22[bit_index] >> bit_shift) :
                          j == 2 ? (g_21[bit_index] >> bit_shift) :
                                   (g_20[bit_index] >> bit_shift)) & 1;
                break;
              case 2:
                dst[h] ^= (j == 1 ? (g_12[bit_index] >> bit_shift) :
                          j == 2 ? (g_11[bit_index] >> bit_shift) :
                                   (g_10[bit_index] >> bit_shift)) & 1;
                break;
              case 47: // 48 - 1
                dst[h] ^= (j == 1 ? (g_42[bit_index] >> bit_shift) :
                          j == 2 ? (g_41[bit_index] >> bit_shift) :
                                   (g_40[bit_index] >> bit_shift)) & 1;
                break;
              case 48:
                dst[h] ^= (j == 1 ? (g_32[bit_index] >> bit_shift) :
                          j == 2 ? (g_31[bit_index] >> bit_shift) :
                                   (g_30[bit_index] >> bit_shift)) & 1;
                break;
              default:
                dst[h] ^= (j == 1 ? (g_02[bit_index] >> bit_shift) :
                          j == 2 ? (g_01[bit_index] >> bit_shift) :
                                   (g_00[bit_index] >> bit_shift)) & 1;
                break;
            }
        }
    }
}
