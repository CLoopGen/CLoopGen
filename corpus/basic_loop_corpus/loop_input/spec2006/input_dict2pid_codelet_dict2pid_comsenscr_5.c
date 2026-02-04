#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef int32 s3pid_t;
typedef s3pid_t s3ssid_t;
typedef short int16;
typedef int16 s3senid_t;

typedef struct {
    s3ssid_t **internal;
    s3ssid_t ***ldiph_lc;
    s3ssid_t **single_lc;
    s3senid_t **comstate;
    s3senid_t **comsseq;
    int32 *comwt;
    int32 n_comstate;
    int32 n_comsseq;
} dict2pid_t;

dict2pid_t *d2p;
int32 *senscr;
int32 *comsenscr;
int32 i;
int32 j;
int32 best;
s3senid_t *comstate;
s3senid_t k;

void init_vars() {
    const int32 total_senscr_size = 1 << 20;
    const int32 max_comstate_entries = 1 << 16;
    const int32 max_state_len = 50;

    d2p = (dict2pid_t*)calloc(1, sizeof(dict2pid_t));
    senscr = (int32*)malloc(total_senscr_size * sizeof(int32));
    comsenscr = (int32*)malloc(max_comstate_entries * sizeof(int32));

    d2p->n_comstate = max_comstate_entries;
    d2p->comwt = (int32*)malloc(max_comstate_entries * sizeof(int32));
    d2p->comstate = (s3senid_t**)malloc(max_comstate_entries * sizeof(s3senid_t*));

    for (int i = 0; i < total_senscr_size; i++) {
        senscr[i] = rand() % 10000;
    }

    for (int i = 0; i < max_comstate_entries; i++) {
        int len = (rand() % (max_state_len - 1)) + 2;
        s3senid_t* state = (s3senid_t*)malloc(len * sizeof(s3senid_t));
        for (int j = 0; j < len - 1; j++) {
            state[j] = rand() % total_senscr_size;
        }
        state[len - 1] = -1;
        d2p->comstate[i] = state;
        d2p->comwt[i] = rand() % 1000;
    }
}