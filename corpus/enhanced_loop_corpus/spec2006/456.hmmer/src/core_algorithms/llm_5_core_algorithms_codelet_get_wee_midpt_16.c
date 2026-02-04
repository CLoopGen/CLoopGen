#include <stdio.h>

#include <inttypes.h>

struct plan7_s {
    char *name;
    char *acc;
    char *desc;
    char *rf;
    char *cs;
    char *ca;
    char *comlog;
    int nseq;
    char *ctime;
    int *map;
    int checksum;
    int *tpri;
    int *mpri;
    int *ipri;
    float ga1;
    float ga2;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    int M;
    float **t;
    float **mat;
    float **ins;
    float tbd1;
    float xt[4][2];
    float *begin;
    float *end;
    float null[20];
    float p1;
    int **tsc;
    int **msc;
    int **isc;
    int xsc[4][2];
    int *bsc;
    int *esc;
    int *tsc_mem;
    int *msc_mem;
    int *isc_mem;
    int *bsc_mem;
    int *esc_mem;
    int **dnam;
    int **dnai;
    int dna2;
    int dna4;
    float mu;
    float lambda;
    int flags;
};


extern struct plan7_s *hmm;
extern char *dsq;
extern int k1;
extern int k3;
extern int **xmx;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int s2;
extern int cur;
extern int prv;
extern int i;
extern int k;
extern int sc;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start + 1; i <= s2; i++) {
    cur = i % 2;
    prv = !cur;

    // Early exit if current sequence index is invalid
    if (i < 0 || dsq == NULL) continue;

    // Initialize all k1 states at once unless we're in a special case
    mmx[cur][k1] = imx[cur][k1] = dmx[cur][k1] = -987654321;

    // Handle insertion at k1 only if k1 is less than model length
    if (k1 < hmm->M) {
        int valid = 0;
        imx[cur][k1] = -987654321;

        sc = mmx[prv][k1] + hmm->tsc[1][k1];
        if (sc > -987654321) {
            imx[cur][k1] = sc;
            valid = 1;
        }

        sc = imx[prv][k1] + hmm->tsc[4][k1];
        if (sc > imx[cur][k1]) {
            imx[cur][k1] = sc;
            valid = 1;
        }

        if (valid && hmm->isc[(int)dsq[i]][k1] != -987654321)
            imx[cur][k1] += hmm->isc[(int)dsq[i]][k1];
        else
            imx[cur][k1] = -987654321;
    }

    // Transition to match from begin state
    sc = xmx[prv][0] + hmm->bsc[k1];
    if (sc > -987654321)
        mmx[cur][k1] = sc;
    else
        mmx[cur][k1] = -987654321;

    if (mmx[cur][k1] != -987654321 && hmm->msc[(int)dsq[i]][k1] != -987654321)
        mmx[cur][k1] += hmm->msc[(int)dsq[i]][k1];
    else
        mmx[cur][k1] = -987654321;

    // Inner loop: process k from k1+1 to k3
    for (k = k1 + 1; k <= k3; k++) {
        // Reset match score
        mmx[cur][k] = -987654321;

        // Gather possible incoming transitions to M state
        if (mmx[prv][k - 1] != -987654321) {
            sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1];
            if (sc > -987654321) mmx[cur][k] = sc;
        }

        if (imx[prv][k - 1] != -987654321) {
            sc = imx[prv][k - 1] + hmm->tsc[3][k - 1];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
        }

        if (xmx[prv][0] != -987654321) {
            sc = xmx[prv][0] + hmm->bsc[k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
        }

        if (dmx[prv][k - 1] != -987654321) {
            sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
        }

        // Apply emission score only if transition was valid
        if (mmx[cur][k] != -987654321 && hmm->msc[(int)dsq[i]][k] != -987654321)
            mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
        else
            mmx[cur][k] = -987654321;

        // D state: only valid for k < M
        dmx[cur][k] = -987654321;
        if (k < hmm->M) {
            sc = -987654321;
            if (mmx[cur][k - 1] != -987654321)
                sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1];
            if (sc > -987654321) dmx[cur][k] = sc;

            sc = -987654321;
            if (dmx[cur][k - 1] != -987654321)
                sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1];
            if (sc > dmx[cur][k]) dmx[cur][k] = sc;
        }

        // I state: only valid for k < M
        imx[cur][k] = -987654321;
        if (k < hmm->M) {
            sc = -987654321;
            if (mmx[prv][k] != -987654321)
                sc = mmx[prv][k] + hmm->tsc[1][k];
            if (sc > -987654321) imx[cur][k] = sc;

            sc = -987654321;
            if (imx[prv][k] != -987654321)
                sc = imx[prv][k] + hmm->tsc[4][k];
            if (sc > imx[cur][k]) imx[cur][k] = sc;

            if (imx[cur][k] != -987654321 && hmm->isc[(int)dsq[i]][k] != -987654321)
                imx[cur][k] += hmm->isc[(int)dsq[i]][k];
            else
                imx[cur][k] = -987654321;
        }
    }

    // X states: E, N, C, J handling
    xmx[cur][4] = -987654321;
    if (xmx[prv][4] != -987654321) {
        sc = xmx[prv][4] + hmm->xsc[0][1];
        if (sc > -987654321) xmx[cur][4] = sc;
    }

    xmx[cur][1] = -987654321;
    for (k = k1; k <= k3 && k <= hmm->M; k++) {
        if (mmx[cur][k] != -987654321) {
            sc = mmx[cur][k] + hmm->esc[k];
            if (sc > xmx[cur][1]) xmx[cur][1] = sc;
        }
    }

    xmx[cur][0] = -987654321;
    if (xmx[cur][4] != -987654321) {
        sc = xmx[cur][4] + hmm->xsc[0][0];
        if (sc > -987654321) xmx[cur][0] = sc;
    }

    xmx[cur][2] = -987654321;
    if (xmx[prv][2] != -987654321) {
        sc = xmx[prv][2] + hmm->xsc[2][1];
        if (sc > -987654321) xmx[cur][2] = sc;
    }

    if (xmx[cur][1] != -987654321) {
        sc = xmx[cur][1] + hmm->xsc[1][0];
        if (sc > xmx[cur][2]) xmx[cur][2] = sc;
    }
}
}
