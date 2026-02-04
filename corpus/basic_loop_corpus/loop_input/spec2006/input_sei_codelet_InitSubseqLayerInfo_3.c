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

subseq_layer_information_struct seiSubseqLayerInfo;
int i;

void init_vars() {
    seiSubseqLayerInfo.bit_rate[0] = 0;
    seiSubseqLayerInfo.bit_rate[1] = 0;
    seiSubseqLayerInfo.frame_rate[0] = 0;
    seiSubseqLayerInfo.frame_rate[1] = 0;
    seiSubseqLayerInfo.data[0] = 0;
    seiSubseqLayerInfo.data[1] = 0;
    seiSubseqLayerInfo.data[2] = 0;
    seiSubseqLayerInfo.data[3] = 0;
    seiSubseqLayerInfo.data[4] = 0;
    seiSubseqLayerInfo.data[5] = 0;
    seiSubseqLayerInfo.data[6] = 0;
    seiSubseqLayerInfo.data[7] = 0;
    seiSubseqLayerInfo.layer_number = 0;
    seiSubseqLayerInfo.payloadSize = 0;
    i = 0;
}