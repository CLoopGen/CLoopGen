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
    // Variant 2: Strided Memory Access Pattern
    // Introduce strided access by processing multiple k indices per iteration
    // to simulate non-unit stride and increase data-level parallelism potential.
    // Use unrolled-like access pattern with fixed step size.

    const int STRIDE = 2;
    int k_start, k_end, k_step;

    for (i = s3 - 1; i >= s2; i--) {
        cur = i % 2;
        nxt = !cur;

        // Initialize boundary states
        xmx[cur][2] = (xmx[nxt][2] + hmm->xsc[2][1] > -987654321) ? 
                      xmx[nxt][2] + hmm->xsc[2][1] : -987654321;

        xmx[cur][0] = -987654321;
        for (k = k1; k <= k3; k++) {
            sc = mmx[nxt][k] + hmm->bsc[k];
            if (sc > xmx[cur][0]) xmx[cur][0] = sc;
        }

        xmx[cur][1] = (xmx[cur][2] + hmm->xsc[1][0] > -987654321) ? 
                      xmx[cur][2] + hmm->xsc[1][0] : -987654321;

        xmx[cur][4] = (xmx[cur][0] + hmm->xsc[0][0] > -987654321) ? 
                      xmx[cur][0] + hmm->xsc[0][0] : -987654321;

        sc = xmx[nxt][4] + hmm->xsc[0][1];
        if (sc > xmx[cur][4]) xmx[cur][4] = sc;

        // Reverse traversal with strided access: process k in descending order with stride
        // This creates non-consecutive memory access pattern across mmx/dmx/imx
        for (int step = 0; step < (k3 - k1 + 1 + STRIDE - 1) / STRIDE; step++) {
            k_start = k3 - step * STRIDE;
            k_end = k_start - STRIDE + 1;
            k_step = -1;

            for (k = k_start; k >= k_end && k >= k1; k += k_step) {
                if (k == hmm->M) {
                    mmx[cur][k] = xmx[cur][1];
                    dmx[cur][k] = -987654321;
                    imx[cur][k] = -987654321;
                    if (i != s2)
                        mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
                    continue;
                }

                // Strided update of mmx: access non-local indices
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

                // Update dmx with strided access
                dmx[cur][k] = -987654321;
                sc = mmx[nxt][k + 1] + hmm->tsc[5][k];
                if (sc > -987654321) dmx[cur][k] = sc;

                sc = dmx[cur][k + 1] + hmm->tsc[6][k];
                if (sc > dmx[cur][k]) dmx[cur][k] = sc;

                // Update imx
                imx[cur][k] = -987654321;
                sc = mmx[nxt][k + 1] + hmm->tsc[3][k];
                if (sc > -987654321) imx[cur][k] = sc;

                sc = imx[nxt][k] + hmm->tsc[4][k];
                if (sc > imx[cur][k]) imx[cur][k] = sc;

                if (i != s2)
                    imx[cur][k] += hmm->isc[(int)dsq[i]][k];
            }
        }
    }
}
