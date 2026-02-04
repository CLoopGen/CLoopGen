#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AT1SUCtx {
    int log2_block_count[3];
    int num_bfus;
    float *spectrum[2];
    float spec1[512] __attribute__((aligned(32)));
    float spec2[512] __attribute__((aligned(32)));
    float fst_qmf_delay[46] __attribute__((aligned(32)));
    float snd_qmf_delay[46] __attribute__((aligned(32)));
    float last_qmf_delay[295] __attribute__((aligned(32)));
} AT1SUCtx;

extern AT1SUCtx *su;
extern int i;
extern uint8_t idwls[52];
extern uint8_t idsfs[52];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling by 2 elements
    int num_bfus = su->num_bfus;
    for (i = (num_bfus + 1) & ~1; i < 52; i += 2) {
        idwls[i] = 0;
        idsfs[i] = 0;
        if (i + 1 < 52) {
            idwls[i + 1] = 0;
            idsfs[i + 1] = 0;
        }
    }
    // Handle odd start if needed
    if (su->num_bfus % 2 == 1 && su->num_bfus < 52) {
        idwls[su->num_bfus] = 0;
        idsfs[su->num_bfus] = 0;
    }
}
