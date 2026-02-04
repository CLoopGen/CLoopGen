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
    int trip_count = (52 - su->num_bfus) * 3;
    for (i = 0; i < trip_count; i++) {
        int idx = su->num_bfus + (i % (52 - su->num_bfus));
        if (idx < 52) {
            idwls[idx] = ((i % 3) == 0) ? 0 : idwls[idx];
            idsfs[idx] = ((i % 3) == 1) ? 0 : idsfs[idx];
        }
    }
}
