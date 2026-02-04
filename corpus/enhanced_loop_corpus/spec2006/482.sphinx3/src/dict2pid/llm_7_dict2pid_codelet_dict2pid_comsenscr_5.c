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
    int32 local_best[256]; // Assume bounded number of states; introduces local storage to break loop-carried flow dependency
    if (d2p->n_comstate > 256) return; // Safety check
    for (i = 0; i < d2p->n_comstate; i++) {
        comstate = d2p->comstate[i];
        local_best[i] = senscr[comstate[0]]; // Store intermediate result to remove in-loop update of shared 'best'
        for (j = 1; ; j++) {
            k = comstate[j];
            if (((k) < 0))
                break;
            if (local_best[i] < senscr[k])
                local_best[i] = senscr[k];
        }
    }
    // Final write outside inner computation: breaks loop-carried dependence on 'best' and enables reordering
    for (i = 0; i < d2p->n_comstate; i++) {
        comsenscr[i] = local_best[i] + d2p->comwt[i];
    }
}
