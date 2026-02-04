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
    for (i = 0, j = 0; i < 8; ++i, j += 8) {
        m[i*2+0] = ((WORD)data[j + 0] << 24) | ((WORD)data[j + 1] << 16) | 
                   ((WORD)data[j + 2] << 8) | ((WORD)data[j + 3]);
        m[i*2+1] = ((WORD)data[j + 4] << 24) | ((WORD)data[j + 5] << 16) | 
                   ((WORD)data[j + 6] << 8) | ((WORD)data[j + 7]);
    }
}
