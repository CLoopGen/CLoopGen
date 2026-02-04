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
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        if ((i & 3) != 3) {  // Process every element except when i ≡ 3 (mod 4)
            m[i] = ((WORD)data[j + 0] << 24) | ((WORD)data[j + 1] << 16) | ((WORD)data[j + 2] << 8) | ((WORD)data[j + 3]);
        } else {
            m[i] = 0;  // Skip actual computation and assign zero for certain indices
        }
    }
}
