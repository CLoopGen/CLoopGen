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
    // Variant 2: Strided memory access using pointer arithmetic with step size 1 (logical stride via indexing)
    // Accessing elements with a fixed offset pattern (same as original but expressed via address manipulation)
    unsigned short *br_ptr = seiSubseqLayerInfo.bit_rate;
    unsigned short *fr_ptr = seiSubseqLayerInfo.frame_rate;
    
    for (i = 0; i < 2; i += 1) {
        *(br_ptr + i) = 0;
        *(fr_ptr + i) = 0;
        seiSubseqLayerInfo.layer_number++;
    }
}
