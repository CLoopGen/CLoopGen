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
    int local_pos = pos;
    int local_payload = seiSubseqLayerInfo.payloadSize;
    for (i = 0; i < seiSubseqLayerInfo.layer_number; i++) {
        *((unsigned short *)&(seiSubseqLayerInfo.data[local_pos])) = seiSubseqLayerInfo.bit_rate[i];
        local_pos += 2;
        *((unsigned short *)&(seiSubseqLayerInfo.data[local_pos])) = seiSubseqLayerInfo.frame_rate[i];
        local_pos += 2;
        local_payload += 4;
    }
    pos = local_pos;
    seiSubseqLayerInfo.payloadSize = local_payload;
}
