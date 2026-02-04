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
    int limit = stride > 5 ? 3 : 2;
    for (i = 0; i < limit; i++) {
        int16_t temp = block[-stride].u.dc[i] * 2;
        block->u.dc[i] += temp;
    }
}
