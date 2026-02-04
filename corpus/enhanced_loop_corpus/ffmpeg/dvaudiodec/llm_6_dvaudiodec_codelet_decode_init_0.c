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
    for (i = 0; i < (sizeof (s->shuffle) / sizeof ((s->shuffle)[0])); i++) {
        const unsigned int a = s->is_pal ? 18 : 15;
        const unsigned int b = 3 * a;
        const int index_mod_b = i % b;
        const int term1 = 80 * ((21 * (i % 3) + 9 * (i / 3) + ((i / a) % 3)) % b);
        const int term2 = (2 + s->is_12bit) * (i / b);
        s->shuffle[i] = term1 + term2 + 8;
    }
}
