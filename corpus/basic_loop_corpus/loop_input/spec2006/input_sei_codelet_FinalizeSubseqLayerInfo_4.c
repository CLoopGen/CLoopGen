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
int pos;

void init_vars() {
    seiSubseqLayerInfo.layer_number = 2;
    seiSubseqLayerInfo.payloadSize = 0;
    seiSubseqLayerInfo.bit_rate[0] = 1000;
    seiSubseqLayerInfo.bit_rate[1] = 2000;
    seiSubseqLayerInfo.frame_rate[0] = 30;
    seiSubseqLayerInfo.frame_rate[1] = 60;
    pos = 0;
}