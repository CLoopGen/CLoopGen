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



void loop() {
    WORD indices[16];
    for (i = 0; i < 16; ++i) {
        indices[i] = i * 4;
    }
    for (i = 0; i < 16; ++i) {
        WORD idx = indices[i];
        m[i] = ((WORD)data[idx + 0] << 24) | ((WORD)data[idx + 1] << 16) | ((WORD)data[idx + 2] << 8) | ((WORD)data[idx + 3]);
    }
}
