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
for (i = 0; i < sh->Ns; i++) {
}

}
