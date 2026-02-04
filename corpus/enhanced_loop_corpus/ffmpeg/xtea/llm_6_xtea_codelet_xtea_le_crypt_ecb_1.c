#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

extern AVXTEA *ctx;
extern uint32_t v0;
extern uint32_t v1;
extern int i;
extern uint32_t delta;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_v1, temp_sum;
    for (i = 0; i < 32; i++) {
        temp_sum = sum - delta;
        temp_v1 = v1 - ((((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + ctx->key[(sum >> 11) & 3]));
        v0 = v0 - ((((temp_v1 << 4) ^ (temp_v1 >> 5)) + temp_v1) ^ (temp_sum + ctx->key[temp_sum & 3]));
        v1 = temp_v1;
        sum = temp_sum;
    }
}
