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
    const unsigned int a = s->is_pal ? 18 : 15;
    const unsigned int b = 3 * a;
    const int size = sizeof(s->shuffle) / sizeof(s->shuffle[0]);
    for (i = 0; i < size; i++) {
        s->shuffle[i] = 80 * ((21 * (i % 3) + 9 * (i / 3) + ((i / a) % 3)) % b) + (2 + s->is_12bit) * (i / b) + 8;
    }
}
