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
    const unsigned int base_offset = 8;
    const unsigned int a = s->is_pal ? 18 : 15;
    const unsigned int b = 3 * a;
    const unsigned int stride = (2 + s->is_12bit);
    const int n = (sizeof(s->shuffle) / sizeof((s->shuffle)[0])) / b;
    for (i = 0; i < n; i++) {
        const int start = i * b;
        const int end = start + b;
        for (int k = start; k < end && k < (sizeof(s->shuffle) / sizeof((s->shuffle)[0])); k++) {
            const int mod3 = k % 3;
            const int div3 = k / 3;
            const int inner_mod = (k / a) % 3;
            const int combined = (21 * mod3 + 9 * div3 + inner_mod) % b;
            s->shuffle[k] = 80 * combined + stride * i + base_offset;
        }
    }
    // Handle remaining elements if total size is not a multiple of b
    for (; i * b < (sizeof(s->shuffle) / sizeof((s->shuffle)[0])); i++) {
        const int k = i * b;
        s->shuffle[k] = 80 * ((21 * (k % 3) + 9 * (k / 3) + ((k / a) % 3)) % b) + stride * i + base_offset;
    }
}
