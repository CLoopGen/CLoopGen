#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union {
    int16_t mv[2][2];
    int16_t dc[3];
};


typedef struct {
    union {
        int16_t mv[2][2];
        int16_t dc[3];
    } u;
    uint8_t ref;
} DiracBlock;

extern DiracBlock *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        block->u.dc[i % 3] += block[-1].u.dc[i % 3];
        if (i + 1 < 6) {
            block->u.dc[(i + 1) % 3] += block[-1].u.dc[(i + 1) % 3];
        }
    }
}
