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
    const int inner_size = 3 * a;
    const int outer_size = (sizeof(s->shuffle) / sizeof(s->shuffle[0]) + b - 1) / b;
    int idx = 0;
    for (int j = 0; j < outer_size; j++) {
        for (int k = 0; k < inner_size; k++) {
            if (idx >= sizeof(s->shuffle) / sizeof(s->shuffle[0])) break;
            s->shuffle[idx] = 80 * ((21 * (k % 3) + 9 * (k / 3) + ((j % 3))) % b) + (2 + s->is_12bit) * j + 8;
            idx++;
        }
    }
}
