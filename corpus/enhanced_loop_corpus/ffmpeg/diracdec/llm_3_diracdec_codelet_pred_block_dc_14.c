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



void loop() {
    // Variant 2: Strided memory access — treat the data as if accessed with a stride of 2 (simulated via index scaling)
    // Although dc has 3 elements, we simulate strided pattern by accessing every element but expressing index linearly
    // Here we use a scaled index expression to mimic more complex access patterns (though effectively same order)
    // This reflects preparation for higher-dimensional or padded layouts
    for (i = 0; i < 3; i++) {
        block->u.dc[0 + i] += block[-stride].u.dc[0 + i];
    }
}
