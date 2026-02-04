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
    int temp_bit_rate[2], temp_frame_rate[2];
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        temp_bit_rate[i] = seiSubseqLayerInfo.bit_rate[i];
        temp_frame_rate[i] = seiSubseqLayerInfo.frame_rate[i];
    }
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        *((unsigned short *)&(seiSubseqLayerInfo.data[pos])) = temp_bit_rate[i];
        pos += 2;
        *((unsigned short *)&(seiSubseqLayerInfo.data[pos])) = temp_frame_rate[i];
        pos += 2;
        seiSubseqLayerInfo.payloadSize += 4;
    }
}
