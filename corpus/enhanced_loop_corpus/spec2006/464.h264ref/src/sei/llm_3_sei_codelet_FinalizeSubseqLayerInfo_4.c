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
    // Variant 2: Strided access - process every second element first, then the others (interleaved pattern)
    int i;
    // First pass: write all bit_rate values with stride
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        *((unsigned short *)&(seiSubseqLayerInfo.data[pos + i * 4])) = seiSubseqLayerInfo.bit_rate[i];
    }
    // Second pass: write all frame_rate values with offset stride
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        *((unsigned short *)&(seiSubseqLayerInfo.data[pos + i * 4 + 2])) = seiSubseqLayerInfo.frame_rate[i];
    }
    pos += 4 * seiSubseqLayerInfo.layer_number;
    seiSubseqLayerInfo.payloadSize += 4 * seiSubseqLayerInfo.layer_number;
}
