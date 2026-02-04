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
    uint8_t temp_idwls[52];
    uint8_t temp_idsfs[52];
    for (int j = su->num_bfus; j < 52; j++) {
        temp_idwls[j] = 0;
        temp_idsfs[j] = 0;
    }
    // Introduce WAW dependency by writing back after temporary use
    for (int j = su->num_bfus; j < 52; j++) {
        idwls[j] = temp_idwls[j];
        idsfs[j] = temp_idsfs[j];
    }
}
