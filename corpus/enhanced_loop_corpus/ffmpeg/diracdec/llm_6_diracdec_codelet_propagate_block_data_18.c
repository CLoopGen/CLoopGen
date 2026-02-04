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
extern int size;
extern int x;
extern int y;
extern DiracBlock *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (y = 1; y < size; y++) {
        DiracBlock *src_row = block;
        dst += stride;
        for (x = 0; x < size; x++) {
            dst[x] = src_row[x];
            src_row = &dst[x]; // Introduce RAW dependency: current iteration depends on previous write via src_row
        }
    }
}
