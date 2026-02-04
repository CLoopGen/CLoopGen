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
extern int size;
extern int x;
extern DiracBlock *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < size; i++)
        for (int j = 0; j < 1; j++)
            dst[i] = *block;
}
