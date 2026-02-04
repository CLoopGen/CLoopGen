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
extern int s3;
extern int **xmx;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int s2;
extern int cur;
extern int nxt;
extern int i;
extern int k;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder inner loop to access memory in a more cache-friendly, consecutive manner
    // by restructuring the k-loop to minimize stride and improve spatial locality.

    for (i = s3 - 1; i >= s2; i--) {
        cur = i % 2;
        nxt = !cur;

        // Initialize xmx values with reduced branching where possible
        xmx[cur][2] = -987654321;
        sc = xmx[nxt][2] + hmm->xsc[2][1];
        if (sc > -987654321) xmx[cur][2] = sc;

        xmx[cur][0] = -987654321;
        xmx[cur][1] = -987654321;
        xmx[cur][4] = -987654321;

        // Combine dependent updates to xmx[0] and xmx[1]/xmx[4] in forward sweep
        for (k = k1; k <= k3; k++) {
            sc = mmx[nxt][k] + hmm->bsc[k];
            if (sc > xmx[cur][0]) xmx[cur][0] = sc;
        }

        sc = xmx[cur][2] + hmm->xsc[1][0];
        if (sc > -987654321) xmx[cur][1] = sc;

        sc = xmx[cur][0] + hmm->xsc[0][0];
        if (sc > -987654321) xmx[cur][4] = sc;

        sc = xmx[nxt][4] + hmm->xsc[0][1];
        if (sc > xmx[cur][4]) xmx[cur][4] = sc;

        // Process k from k3 down to k1, but reorder field accesses to group by row usage
        // to promote consecutive memory access in mmx, dmx, imx
        for (k = k3; k >= k1; k--) {
            int idx = k;
            if (idx == hmm->M) {
                mmx[cur][idx] = xmx[cur][1];
                dmx[cur][idx] = -987654321;
                imx[cur][idx] = -987654321;
                if (i != s2)
                    mmx[cur][idx] += hmm->msc[(int)dsq[i]][idx];
                continue;
            }

            // Update mmx: use current and next rows, grouped for locality
            mmx[cur][idx] = -987654321;
            sc = xmx[cur][1] + hmm->esc[idx];
            if (sc > -987654321) mmx[cur][idx] = sc;

            sc = mmx[nxt][idx + 1] + hmm->tsc[0][idx];
            if (sc > mmx[cur][idx]) mmx[cur][idx] = sc;

            sc = imx[nxt][idx] + hmm->tsc[1][idx];
            if (sc > mmx[cur][idx]) mmx[cur][idx] = sc;

            sc = dmx[cur][idx + 1] + hmm->tsc[2][idx];
            if (sc > mmx[cur][idx]) mmx[cur][idx] = sc;

            if (i != s2)
                mmx[cur][idx] += hmm->msc[(int)dsq[i]][idx];

            // Update dmx
            dmx[cur][idx] = -987654321;
            sc = mmx[nxt][idx + 1] + hmm->tsc[5][idx];
            if (sc > -987654321) dmx[cur][idx] = sc;

            sc = dmx[cur][idx + 1] + hmm->tsc[6][idx];
            if (sc > dmx[cur][idx]) dmx[cur][idx] = sc;

            // Update imx
            imx[cur][idx] = -987654321;
            sc = mmx[nxt][idx + 1] + hmm->tsc[3][idx];
            if (sc > -987654321) imx[cur][idx] = sc;

            sc = imx[nxt][idx] + hmm->tsc[4][idx];
            if (sc > imx[cur][idx]) imx[cur][idx] = sc;

            if (i != s2)
                imx[cur][idx] += hmm->isc[(int)dsq[i]][idx];
        }
    }
}
