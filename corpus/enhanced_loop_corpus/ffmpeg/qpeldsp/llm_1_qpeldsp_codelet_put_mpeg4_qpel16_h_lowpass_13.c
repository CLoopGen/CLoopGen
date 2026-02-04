#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < h; i++) {
        int base_idx[17];
        for (int k = 0; k <= 16; k++) {
            base_idx[k] = src[k];
        }
        for (int j = 0; j < 16; j++) {
            int sum_pair_1 = base_idx[j] + base_idx[j+1];
            int sum_pair_2 = base_idx[j-1 >= 0 ? j-1 : 16] + base_idx[j+2 <= 16 ? j+2 : 16];
            int sum_pair_3 = base_idx[j-2 >= 0 ? j-2 : 16] + base_idx[j+3 <= 16 ? j+3 : 16];
            int sum_pair_4 = base_idx[j-3 >= 0 ? j-3 : 16] + base_idx[j+4 <= 16 ? j+4 : 16];

            int term1 = sum_pair_1 * 20;
            int term2 = sum_pair_2 * 6;
            int term3 = sum_pair_3 * 3;
            int term4 = sum_pair_4;

            int index = (term1 - term2 + term3 - term4 + 16) >> 5;
            dst[j] = cm[index];
        }
        dst += dstStride;
        src += srcStride;
    }
}
