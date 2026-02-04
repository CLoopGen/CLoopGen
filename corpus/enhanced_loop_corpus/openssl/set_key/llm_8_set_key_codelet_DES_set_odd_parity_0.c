#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  unsigned char odd_parity[256];
extern DES_cblock *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (sizeof(DES_cblock)) * 2; i += 2) {
        uint8_t temp1 = (*key)[i/2];
        uint8_t temp2 = odd_parity[temp1];
        (*key)[i/2] = temp2 ^ 0x01;
    }
}
