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
for (i = 0; i < 2; i++) {
    seiSubseqLayerInfo.bit_rate[i] = 0;
    if (i > 0) {
        seiSubseqLayerInfo.frame_rate[i] = 0;
        seiSubseqLayerInfo.layer_number++;
    }
}
}
