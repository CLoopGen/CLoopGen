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
    for (y = 1; y < size; y += 2) {
        dst += stride * 2;
        for (x = 0; x < size; x++) {
            dst[x] = *block;
            if (x + 1 < size) {
                dst[x + 1] = *block;
            }
        }
        if (y + 1 < size) {
            DiracBlock *temp = dst - stride;
            for (x = 0; x < size; x++) {
                temp[x] = *block;
            }
        }
    }
}
