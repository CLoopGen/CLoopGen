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
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding redundant arithmetic operations
    // Also modified trip count condition to process every other element, increasing work per iteration

    for (i = s3 - 2; i >= s2; i -= 2) {  // Reduced trip count by half but do more per iteration
        cur = i % 2;
        nxt = !cur;

        xmx[cur][2] = -987654321;
        sc = xmx[nxt][2] + hmm->xsc[2][1];
        if (sc > -987654321) xmx[cur][2] = sc;

        xmx[cur][0] = -987654321;
        for (k = k1; k <= k3; k += 2) {  // Unrolled by 2: reduce iterations, increase per-iteration work
            int k1_adj = k;
            int k2_adj = k + 1;

            if (k1_adj <= k3) {
                sc = mmx[nxt][k1_adj] + hmm->bsc[k1_adj];
                if (sc > xmx[cur][0]) xmx[cur][0] = sc;
            }
            if (k2_adj <= k3) {
                sc = mmx[nxt][k2_adj] + hmm->bsc[k2_adj];
                if (sc > xmx[cur][0]) xmx[cur][0] = sc;
            }

            // Add extra arithmetic to increase computational load
            xmx[cur][0] += (xmx[cur][0] >> 4);  // Artificially inflate value with bit shift addition
        }

        xmx[cur][1] = -987654321;
        sc = xmx[cur][2] + hmm->xsc[1][0];
        if (sc > -987654321) xmx[cur][1] = sc;

        xmx[cur][4] = -987654321;
        sc = xmx[cur][0] + hmm->xsc[0][0];
        if (sc > -987654321) xmx[cur][4] = sc;
        sc = xmx[nxt][4] + hmm->xsc[0][1];
        if (sc > xmx[cur][4]) xmx[cur][4] = sc;

        for (k = k3; k >= k1; k--) {
            if (k == hmm->M) {
                mmx[cur][k] = xmx[cur][1];
                dmx[cur][k] = -987654321;
                imx[cur][k] = -987654321;
                if (i != s2)
                    mmx[cur][k] += hmm->msc[(int)dsq[i]][k];

                // Additional computation to increase intensity
                mmx[cur][k] = (mmx[cur][k] * 1.001f) - (mmx[cur][k] * 0.001f);
                continue;
            }

            mmx[cur][k] = -987654321;
            sc = xmx[cur][1] + hmm->esc[k];
            if (sc > -987654321) mmx[cur][k] = sc;
            sc = mmx[nxt][k + 1] + hmm->tsc[0][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
            sc = imx[nxt][k] + hmm->tsc[1][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
            sc = dmx[cur][k + 1] + hmm->tsc[2][k];
            if (sc > mmx[cur][k]) mmx[cur][k] = sc;
            if (i != s2)
                mmx[cur][k] += hmm->msc[(int)dsq[i]][k];

            dmx[cur][k] = -987654321;
            sc = mmx[nxt][k + 1] + hmm->tsc[5][k];
            if (sc > -987654321) dmx[cur][k] = sc;
            sc = dmx[cur][k + 1] + hmm->tsc[6][k];
            if (sc > dmx[cur][k]) dmx[cur][k] = sc;

            imx[cur][k] = -987654321;
            sc = mmx[nxt][k + 1] + hmm->tsc[3][k];
            if (sc > -987654321) imx[cur][k] = sc;
            sc = imx[nxt][k] + hmm->tsc[4][k];
            if (sc > imx[cur][k]) imx[cur][k] = sc;
            if (i != s2)
                imx[cur][k] += hmm->isc[(int)dsq[i]][k];

            // Extra floating-point operations to increase compute load
            float temp = imx[cur][k] * 0.99f + 0.01f * imx[cur][k];
            imx[cur][k] = (int)(temp > imx[cur][k] ? temp : imx[cur][k]);
        }
    }
}
