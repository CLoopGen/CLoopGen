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
for (i = su->num_bfus; i < 52; i++)
    idwls[i] = idsfs[i] = 0;

}
