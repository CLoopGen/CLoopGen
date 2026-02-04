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
extern int stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    block->u.dc[0] += block[-stride].u.dc[0];
    block->u.dc[1] += block[-stride].u.dc[1];
    block->u.dc[2] += block[-stride].u.dc[2];
}
