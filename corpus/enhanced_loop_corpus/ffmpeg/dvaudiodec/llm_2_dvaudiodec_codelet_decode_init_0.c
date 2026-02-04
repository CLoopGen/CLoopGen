#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DVAudioContext {
    int block_size;
    int is_12bit;
    int is_pal;
    int16_t shuffle[2000];
} DVAudioContext;

extern DVAudioContext *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the shuffle array with a stride of 2,
    // processing even indices first, then odd indices in a second pass.
    const unsigned int a = s->is_pal ? 18 : 15;
    const unsigned int b = 3 * a;
    const int len = sizeof(s->shuffle) / sizeof(s->shuffle[0]);
    
    for (int pass = 0; pass < 2; pass++) {
        for (i = pass; i < len; i += 2) {
            s->shuffle[i] = 80 * ((21 * (i % 3) + 9 * (i / 3) + ((i / a) % 3)) % b) + (2 + s->is_12bit) * (i / b) + 8;
        }
    }
}
