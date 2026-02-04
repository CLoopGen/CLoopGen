#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint8_t BYTE;

typedef uint32_t WORD;

extern  BYTE data[];
extern WORD i;
extern WORD j;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; ++i) {
        m[i] = ((WORD)data[i * 2 + 0] << 24) | 
               ((WORD)data[i * 2 + 1] << 16) | 
               ((WORD)data[(i * 2 + 0) % 64] << 8) | 
               ((WORD)data[(i * 2 + 1) % 64]);
    }
}
