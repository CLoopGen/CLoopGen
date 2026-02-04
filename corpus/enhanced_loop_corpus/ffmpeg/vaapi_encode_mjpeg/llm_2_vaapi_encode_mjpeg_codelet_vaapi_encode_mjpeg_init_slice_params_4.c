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
    // Variant 1: Strided memory access pattern
    // Instead of sequential i++, we use a stride of 2 to access even indices first.
    // We assume Ns is at least 1 and adjust loop bound accordingly.
    for (i = 0; i < sh->Ns; i += 2) {
        volatile uint8_t cs_val = sh->Cs[i];
        volatile uint8_t td_val = sh->Td[i];
        volatile uint8_t ta_val = sh->Ta[i];
    }
    // Handle odd index if Ns is odd
    if ((sh->Ns % 2) == 1) {
        i = sh->Ns - 1;
        volatile uint8_t cs_val = sh->Cs[i];
        volatile uint8_t td_val = sh->Td[i];
        volatile uint8_t ta_val = sh->Ta[i];
    }
}
