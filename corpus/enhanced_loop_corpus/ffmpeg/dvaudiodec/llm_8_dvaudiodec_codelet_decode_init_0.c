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
    const unsigned int block = s->block_size > 0 ? s->block_size : 1;
    for (i = 0; i < (sizeof(s->shuffle) / sizeof((s->shuffle)[0])); i += block) {
        for (int j = 0; j < block && (i + j) < (sizeof(s->shuffle) / sizeof((s->shuffle)[0])); j++) {
            const int idx = i + j;
            const int term1 = (21 * (idx % 3) + 9 * (idx / 3) + ((idx / a) % 3)) % b;
            const int term2 = (2 + s->is_12bit) * (idx / b);
            s->shuffle[idx] = 80 * term1 + term2 + 8;
        }
    }
}
