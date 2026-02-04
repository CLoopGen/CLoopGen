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
    // Use transposed access pattern: iterate by diagonal bands to change memory access order
    for (int d = 0; d < 95; d++) { // Diagonal index from 0 to (48+48-2)
        for (int i_start = (d < 48 ? 0 : d - 47); i_start <= (d < 48 ? d : 47); i_start++) {
            i = i_start;
            j = d - i;
            if (i >= 48 || j >= 48) continue;

            h = i + j * 48;
            k = 0;
            for (l = i - 2; l <= i + 2; l++) {
                for (m = j - 2; m <= j; m++) {
                    if (l <= 0 || (l >= i && m == j))
                        continue;
                    if (l >= 0 && l < 48 && m > 0 && m < 48) {
                        // Consecutive block access: reorder indexing for better locality
                        int idx = l + (m * 48);
                        k = (k << 1) | (src[idx] & 1);
                    }
                }
            }
            int table_index = k >> 3;
            int shift = 7 - (k & 7);
            if (i == 1) {
                dst[h] ^= ((j == 1 ? g_22[table_index] :
                           j == 2 ? g_21[table_index] :
                                    g_20[table_index]) >> shift) & 1;
            } else if (i == 2) {
                dst[h] ^= ((j == 1 ? g_12[table_index] :
                           j == 2 ? g_11[table_index] :
                                    g_10[table_index]) >> shift) & 1;
            } else if (i == 47) {
                dst[h] ^= ((j == 1 ? g_42[table_index] :
                           j == 2 ? g_41[table_index] :
                                    g_40[table_index]) >> shift) & 1;
            } else if (i == 48) {
                dst[h] ^= ((j == 1 ? g_32[table_index] :
                           j == 2 ? g_31[table_index] :
                                    g_30[table_index]) >> shift) & 1;
            } else {
                dst[h] ^= ((j == 1 ? g_02[table_index] :
                           j == 2 ? g_01[table_index] :
                                    g_00[table_index]) >> shift) & 1;
            }
        }
    }
}
