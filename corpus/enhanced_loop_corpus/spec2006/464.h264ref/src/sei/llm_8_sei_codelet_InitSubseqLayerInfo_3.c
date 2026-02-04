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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    for (i = 0; i < 4; i++) {
        int idx = i >> 1;  // Equivalent to i / 2, maps 0,1->0 and 2,3->1
        seiSubseqLayerInfo.bit_rate[idx] += (i * i) + 5;
        seiSubseqLayerInfo.frame_rate[idx] += (i + 1) * (i + 1);
        seiSubseqLayerInfo.layer_number += (i % 2 == 0) ? 1 : 0;
        seiSubseqLayerInfo.payloadSize += idx * 10;
    }
}
