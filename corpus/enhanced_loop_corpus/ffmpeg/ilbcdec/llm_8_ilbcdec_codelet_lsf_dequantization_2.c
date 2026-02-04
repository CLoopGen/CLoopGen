#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t lsf_dim_codebook[];
extern  uint8_t lsf_size_codebook[];
extern  int16_t lsf_codebook[1088];
extern int16_t *lsfdeq;
extern int16_t *_usr_index;
extern int i;
extern int j;
extern int pos;
extern int cb_pos;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (i = 0; i < 6; i++) {
    int factor = (i < 3) ? lsf_dim_codebook[i] : lsf_dim_codebook[5 - i];
    for (j = 0; j < factor; j++) {
        int idx = (i < 3) ? index[3 + i] * lsf_dim_codebook[i] + j : index[3 + (5 - i)] * lsf_dim_codebook[5 - i] + j;
        lsfdeq[10 + pos + j] = lsf_codebook[cb_pos + idx];
    }
    pos += factor;
    cb_pos += lsf_size_codebook[(i < 3) ? i : 5 - i] * factor;
}
}
