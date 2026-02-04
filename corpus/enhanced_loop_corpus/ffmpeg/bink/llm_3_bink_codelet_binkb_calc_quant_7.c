#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t binkb_intra_seed[64];
extern  uint8_t binkb_inter_seed[64];
extern  uint8_t binkb_num[16];
extern  uint8_t binkb_den[16];
extern int32_t binkb_intra_quant[16][64];
extern int32_t binkb_inter_quant[16][64];
extern uint8_t inv_bink_scan[64];
extern  int s[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use consecutive, linear access by precomputing scan order and iterating in data layout order
    // We reverse the indirection by creating a temporary map from natural order to inv_bink_scan order
    int scan_order[64];
    for (int temp_i = 0; temp_i < 64; temp_i++) {
        scan_order[inv_bink_scan[temp_i]] = temp_i;
    }

    for (j = 0; j < 16; j++) {
        for (int k = 0; k < 64; k++) {  // Now k is in natural increasing order (consecutive access)
            int idx = scan_order[k];   // Map k back to original index
            binkb_intra_quant[j][k] = binkb_intra_seed[idx] * (int64_t)s[idx] * binkb_num[j] / (binkb_den[j] * ((1LL << 30) >> 12));
            binkb_inter_quant[j][k] = binkb_inter_seed[idx] * (int64_t)s[idx] * binkb_num[j] / (binkb_den[j] * ((1LL << 30) >> 12));
        }
    }
}
