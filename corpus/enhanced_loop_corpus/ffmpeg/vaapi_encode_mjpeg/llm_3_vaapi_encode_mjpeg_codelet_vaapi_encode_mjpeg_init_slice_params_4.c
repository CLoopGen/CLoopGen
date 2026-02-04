#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct JPEGRawScanHeader {
    uint16_t Ls;
    uint8_t Ns;
    uint8_t Cs[255];
    uint8_t Td[255];
    uint8_t Ta[255];
    uint8_t Ss;
    uint8_t Se;
    uint8_t Ah;
    uint8_t Al;
} JPEGRawScanHeader;

extern JPEGRawScanHeader *sh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping array
    // Simulate indirect access using a permutation index array.
    // For simplicity, we create a static index remapping (reversed order).
    int indices[255];
    for (int j = 0; j < sh->Ns; j++) {
        indices[j] = sh->Ns - 1 - j;  // reverse access order
    }
    for (i = 0; i < sh->Ns; i++) {
        int idx = indices[i];  // indirect access index
        volatile uint8_t cs_val = sh->Cs[idx];
        volatile uint8_t td_val = sh->Td[idx];
        volatile uint8_t ta_val = sh->Ta[idx];
    }
}
