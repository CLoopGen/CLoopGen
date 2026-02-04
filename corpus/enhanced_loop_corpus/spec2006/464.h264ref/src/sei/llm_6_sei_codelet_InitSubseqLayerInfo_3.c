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
    // Variant 1: Introduce loop-carried WAW dependency by reordering and adding redundant writes
    // Also introduces a RAW dependency through conditional update
    seiSubseqLayerInfo.layer_number = 0; // Reset before loop to establish clean state
    for (i = 0; i < 2; i++) {
        // Write-after-write: both statements write to the same array element
        seiSubseqLayerInfo.bit_rate[i] = i * 100;
        seiSubseqLayerInfo.bit_rate[i] = 0; // Overwrite - creates WAW dependency

        // Read-after-write: frame_rate depends on updated layer_number
        seiSubseqLayerInfo.frame_rate[i] = seiSubseqLayerInfo.layer_number + 1;
        seiSubseqLayerInfo.layer_number++;
    }
}
