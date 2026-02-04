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
    for (i = 0; i < 1; i++) {
        int16_t temp0 = block[-1].u.dc[0];
        int16_t temp1 = block[-1].u.dc[1];
        int16_t temp2 = block[-1].u.dc[2];
        block->u.dc[0] += temp0;
        block->u.dc[1] += temp1;
        block->u.dc[2] += temp2;
    }
}
