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
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Traversal
    for (i = d2p->n_comstate - 1; i >= 0; i--) {
        comstate = d2p->comstate[i];
        best = senscr[comstate[0]];
        for (j = 2; ; j += 2) {  // Strided access by step of 2
            if (((comstate[j-1]) < 0))
                break;
            if (best < senscr[comstate[j-1]])
                best = senscr[comstate[j-1]];
            if (((comstate[j]) < 0))
                break;
            if (best < senscr[comstate[j]])
                best = senscr[comstate[j]];
        }
        // Handle odd-length case if broken at j-1
        if (((comstate[j-1]) >= 0) && ((comstate[j]) < 0)) {
            if (best < senscr[comstate[j-1]])
                best = senscr[comstate[j-1]];
        }
        comsenscr[i] = best + d2p->comwt[i];
    }
}
