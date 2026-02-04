#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVBlowfish {
    uint32_t p[18];
    uint32_t s[4][256];
} AVBlowfish;

extern  uint32_t orig_p[18];
extern AVBlowfish *ctx;
extern  uint8_t *key;
extern int key_len;
extern uint32_t data;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 + 2; ++i) {
        data = 0;
        k = 0;
        for (int bit_shift = 24; bit_shift >= 0; bit_shift -= 8) {
            data |= ((uint32_t)key[j] << bit_shift);
            if (++j >= key_len)
                j = 0;
            k++;
        }
        ctx->p[i] = orig_p[i] ^ data;
    }
}
