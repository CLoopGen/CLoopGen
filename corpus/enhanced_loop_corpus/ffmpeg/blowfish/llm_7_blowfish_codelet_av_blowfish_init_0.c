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
        uint32_t local_data = 0;
        int local_j = j;
        for (k = 0; k < 4; k++) {
            local_data = (local_data << 8) | key[local_j];
            local_j = (local_j + 1) % key_len;
        }
        j = local_j;
        ctx->p[i] = orig_p[i] ^ local_data;
    }
}
