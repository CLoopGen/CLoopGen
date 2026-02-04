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
    // Variant with reduced loop-carried dependencies and unrolled dependency chains
    // Use local accumulators to break artificial dependencies on 'sc' and 'xmx'
    for (i = s3 - 1; i >= s2; i--) {
        cur = i % 2;
        nxt = !cur;

        // Break WAW on xmx[cur][*] by using independent computation paths
        int xmx0_candidate = -987654321;
        for (k = k1; k <= k3; k++) {
            int bsc_val = mmx[nxt][k] + hmm->bsc[k];
            if (bsc_val > xmx0_candidate) xmx0_candidate = bsc_val;
        }

        int xmx2_val = (xmx[nxt][2] + hmm->xsc[2][1]) > -987654321 ? (xmx[nxt][2] + hmm->xsc[2][1]) : -987654321;
        int xmx1_val = (xmx2_val + hmm->xsc[1][0]) > -987654321 ? (xmx2_val + hmm->xsc[1][0]) : -987654321;
        int xmx4_val = (xmx0_candidate + hmm->xsc[0][0]) > -987654321 ? (xmx0_candidate + hmm->xsc[0][0]) : -987654321;
        int xmx4_alt = xmx[nxt][4] + hmm->xsc[0][1];
        if (xmx4_alt > xmx4_val) xmx4_val = xmx4_alt;

        // Write final values only once
        xmx[cur][0] = xmx0_candidate;
        xmx[cur][1] = xmx1_val;
        xmx[cur][2] = xmx2_val;
        xmx[cur][4] = xmx4_val;

        // Eliminate loop-carried dependency on 'sc' by using per-element temps
        for (k = k3; k >= k1; k--) {
            if (k == hmm->M) {
                mmx[cur][k] = xmx[cur][1];
                dmx[cur][k] = -987654321;
                imx[cur][k] = -987654321;
                if (i != s2)
                    mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
                continue;
            }

            // No shared 'sc' variable — each path uses its own score
            int mmx_score = -987654321;
            int tmp = xmx[cur][1] + hmm->esc[k];
            if (tmp > -987654321) mmx_score = tmp;

            tmp = mmx[nxt][k + 1] + hmm->tsc[0][k];
            if (tmp > mmx_score) mmx_score = tmp;

            tmp = imx[nxt][k] + hmm->tsc[1][k];
            if (tmp > mmx_score) mmx_score = tmp;

            tmp = dmx[cur][k + 1] + hmm->tsc[2][k];
            if (tmp > mmx_score) mmx_score = tmp;

            if (i != s2)
                mmx_score += hmm->msc[(int)dsq[i]][k];
            mmx[cur][k] = mmx_score;

            int dmx_score = -987654321;
            tmp = mmx[nxt][k + 1] + hmm->tsc[5][k];
            if (tmp > -987654321) dmx_score = tmp;

            tmp = dmx[cur][k + 1] + hmm->tsc[6][k];
            if (tmp > dmx_score) dmx_score = tmp;
            dmx[cur][k] = dmx_score;

            int imx_score = -987654321;
            tmp = mmx[nxt][k + 1] + hmm->tsc[3][k];
            if (tmp > -987654321) imx_score = tmp;

            tmp = imx[nxt][k] + hmm->tsc[4][k];
            if (tmp > imx_score) imx_score = tmp;

            if (i != s2)
                imx_score += hmm->isc[(int)dsq[i]][k];
            imx[cur][k] = imx_score;
        }
    }
}
