#include <stdio.h>

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

extern dict2pid_t *d2p;
extern int32 *senscr;
extern int32 *comsenscr;
extern int32 i;
extern int32 j;
extern int32 best;
extern s3senid_t *comstate;
extern s3senid_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 i_outer;
for (i_outer = 0; i_outer < d2p->n_comstate; i_outer++) {
    i = i_outer;
    comstate = d2p->comstate[i];
    best = senscr[comstate[0]];
    for (j = 1; j < d2p->n_comsseq; j++) {
        k = comstate[j];
        if (((k) < 0))
            break;
        if (best < senscr[k])
            best = senscr[k];
    }
    comsenscr[i] = best + d2p->comwt[i];
}
}
