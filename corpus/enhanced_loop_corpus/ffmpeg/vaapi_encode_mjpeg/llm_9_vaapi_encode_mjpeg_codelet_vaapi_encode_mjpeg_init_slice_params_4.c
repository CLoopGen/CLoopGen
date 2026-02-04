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
    int limit = (sh->Ns > 5) ? 5 : sh->Ns;
    for (i = 0; i < limit; i += 2) {
        uint8_t temp = sh->Cs[i] + sh->Td[i];
        sh->Ss += temp * temp;
        sh->Al = (sh->Al + 1) & 0x0F;
        if (i + 1 < sh->Ns) {
            sh->Ta[i+1] = sh->Ta[i] ^ sh->Cs[i];
        }
    }
}
