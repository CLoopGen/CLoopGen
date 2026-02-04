#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

typedef struct {
    unsigned short bit_rate[2];
    unsigned short frame_rate[2];
    byte data[8];
    int layer_number;
    int payloadSize;
} subseq_layer_information_struct;

extern subseq_layer_information_struct seiSubseqLayerInfo;
extern int i;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic instead of indexing
    unsigned short *data_ptr = (unsigned short *)&seiSubseqLayerInfo.data[pos];
    int i;
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        *data_ptr++ = seiSubseqLayerInfo.bit_rate[i];
        *data_ptr++ = seiSubseqLayerInfo.frame_rate[i];
    }
    pos += 2 * seiSubseqLayerInfo.layer_number * 2; // Update pos: 2 shorts per layer, each 2 bytes
    seiSubseqLayerInfo.payloadSize += 4 * seiSubseqLayerInfo.layer_number;
}
