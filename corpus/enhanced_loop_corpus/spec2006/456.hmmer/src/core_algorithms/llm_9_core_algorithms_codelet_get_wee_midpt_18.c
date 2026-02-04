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
    // Variant 2: Reduced computational intensity with simplified logic and early exits
    // Loop runs fewer iterations and skips certain states based on a stride pattern
    // Uses tighter bounds and avoids redundant checks

    int step = 3;  // Increase stride to reduce effective trip count significantly
    for (i = s3 - 1; i >= s2; i -= step) {
        cur = i % 2;
        nxt = !cur;

        // Simplify initializations with direct assignments where possible
        xmx[cur][2] = xmx[nxt][2] + hmm->xsc[2][1];  // Always assign, skip comparison
        xmx[cur][0] = -987654321;
        for (k = k1; k <= k3 && k < hmm->M; k++) {  // Early exit at hmm->M
            sc = mmx[nxt][k] + hmm->bsc[k];
            if (sc > xmx[cur][0]) xmx[cur][0] = sc;
        }

        xmx[cur][1] = xmx[cur][2] + hmm->xsc[1][0];
        xmx[cur][4] = xmx[cur][0] + hmm->xsc[0][0];
        if (xmx[nxt][4] + hmm->xsc[0][1] > xmx[cur][4])
            xmx[cur][4] = xmx[nxt][4] + hmm->xsc[0][1];

        // Reverse loop with reduced scope: only process first few k values
        int limit = (k3 - k1 > 5) ? k1 + 5 : k3;  // Cap inner loop to at most 5 iterations
        for (k = limit; k >= k1; k--) {
            if (k == hmm->M) {
                mmx[cur][k] = xmx[cur][1];
                dmx[cur][k] = -987654321;
                imx[cur][k] = -987654321;
                if (i != s2)
                    mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
                continue;
            }

            // Reduce number of comparisons: merge conditions where safe
            mmx[cur][k] = xmx[cur][1] + hmm->esc[k];
            sc = mmx[nxt][k + 1] + hmm->tsc[0][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
            sc = imx[nxt][k] + hmm->tsc[1][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
            sc = dmx[cur][k + 1] + hmm->tsc[2][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;

            if (i != s2)
                mmx[cur][k] += hmm->msc[(int)dsq[i]][k];

            dmx[cur][k] = mmx[nxt][k + 1] + hmm->tsc[5][k];
            sc = dmx[cur][k + 1] + hmm->tsc[6][k];
            if (sc > dmx[cur][k]) dmx[cur][k] = sc;

            imx[cur][k] = mmx[nxt][k + 1] + hmm->tsc[3][k];
            sc = imx[nxt][k] + hmm->tsc[4][k];
            if (sc > imx[cur][k]) imx[cur][k] = sc;

            if (i != s2)
                imx[cur][k] += hmm->isc[(int)dsq[i]][k];
        }
    }
}
