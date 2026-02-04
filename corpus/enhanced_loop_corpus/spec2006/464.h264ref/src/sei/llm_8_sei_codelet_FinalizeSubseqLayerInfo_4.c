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
    int limit = seiSubseqLayerInfo.layer_number * 2;
    for (i = 0; i < limit; i += 2) {
        if (i/2 < seiSubseqLayerInfo.layer_number) {
            *((unsigned short *)&(seiSubseqLayerInfo.data[pos])) = seiSubseqLayerInfo.bit_rate[i/2];
            pos += 2;
            *((unsigned short *)&(seiSubseqLayerInfo.data[pos])) = seiSubseqLayerInfo.frame_rate[i/2];
            pos += 2;
            seiSubseqLayerInfo.payloadSize += 4;
        }
    }
}
