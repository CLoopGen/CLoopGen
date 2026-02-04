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


extern char *dsq;
extern int L;
extern struct plan7_s *hmm;
extern int **xmx;
extern int **mmx;
extern int **dmx;
extern int **imx;
extern int **xtr;
extern int **mtr;
extern int **dtr;
extern int **itr;
extern int *btr;
extern int *etr;
extern int sc;
extern int i;
extern int k;
extern int cur;
extern int prv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Loop Interchange Simulation
    // Simulate strided access by reordering computation to emphasize vertical traversal (across 'i') for certain arrays.
    // However, since full loop interchange isn't feasible due to data dependency on `i`, we use blocking/tile-like access
    // over chunks of `i` and `k` to create predictable stride patterns.

    const int BLOCK_SIZE = 16;
    int i_end;

    // Zero-initialize boundary conditions if needed (assumed done externally)
    for (i = 1; i <= L; i += BLOCK_SIZE) {
        i_end = (i + BLOCK_SIZE > L) ? L : i + BLOCK_SIZE;

        for (int ib = i; ib <= i_end; ib++) {
            cur = ib % 2;
            prv = !cur;

            // Reset current row
            mmx[cur][0] = imx[cur][0] = dmx[cur][0] = -987654321;

            // Process k in blocked fashion to encourage reuse of dsq[ib], hmm structs
            for (k = 1; k <= hmm->M; k++) {
                // M-state: Match state update from previous states
                mmx[cur][k] = -987654321;
                sc = -987654321;

                // Transition from M_{k-1}
                if ((sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1]) > -987654321) {
                    mmx[cur][k] = sc;
                    mtr[cur][k] = mtr[prv][k - 1];
                }
                // Transition from I_{k-1}
                if ((sc = imx[prv][k - 1] + hmm->tsc[3][k - 1]) > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtr[cur][k] = itr[prv][k - 1];
                }
                // Transition from BEGIN
                if ((sc = xmx[prv][0] + hmm->bsc[k]) > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtr[cur][k] = ib - 1;
                }
                // Transition from D_{k-1}
                if ((sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1]) > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtr[cur][k] = dtr[prv][k - 1];
                }

                // Emission score addition
                if (hmm->msc[(int)dsq[ib]][k] != -987654321)
                    mmx[cur][k] += hmm->msc[(int)dsq[ib]][k];
                else
                    mmx[cur][k] = -987654321;

                // D-state: Deletion state update
                dmx[cur][k] = -987654321;
                if ((sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1]) > -987654321) {
                    dmx[cur][k] = sc;
                    dtr[cur][k] = mtr[cur][k - 1];
                }
                if ((sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1]) > dmx[cur][k]) {
                    dmx[cur][k] = sc;
                    dtr[cur][k] = dtr[cur][k - 1];
                }

                // I-state: Insertion state (only for k < M)
                if (k < hmm->M) {
                    imx[cur][k] = -987654321;
                    if ((sc = mmx[prv][k] + hmm->tsc[1][k]) > -987654321) {
                        imx[cur][k] = sc;
                        itr[cur][k] = mtr[prv][k];
                    }
                    if ((sc = imx[prv][k] + hmm->tsc[4][k]) > imx[cur][k]) {
                        imx[cur][k] = sc;
                        itr[cur][k] = itr[prv][k];
                    }
                    if (hmm->isc[(int)dsq[ib]][k] != -987654321)
                        imx[cur][k] += hmm->isc[(int)dsq[ib]][k];
                    else
                        imx[cur][k] = -987654321;
                }
            }

            // X-state updates remain sequential but use blocked i access
            xmx[cur][4] = -987654321;
            if ((sc = xmx[prv][4] + hmm->xsc[0][1]) > -987654321)
                xmx[cur][4] = sc;

            xmx[cur][1] = -987654321;
            for (k = 1; k <= hmm->M; k++) {
                if ((sc = mmx[cur][k] + hmm->esc[k]) > xmx[cur][1]) {
                    xmx[cur][1] = sc;
                    etr[ib] = mtr[cur][k];
                }
            }

            xmx[cur][3] = -987654321;
            if ((sc = xmx[prv][3] + hmm->xsc[3][1]) > -987654321) {
                xmx[cur][3] = sc;
                xtr[cur][3] = xtr[prv][3];
            }
            if ((sc = xmx[cur][1] + hmm->xsc[1][1]) > xmx[cur][3]) {
                xmx[cur][3] = sc;
                xtr[cur][3] = ib;
            }

            xmx[cur][0] = -987654321;
            if ((sc = xmx[cur][4] + hmm->xsc[0][0]) > -987654321) {
                xmx[cur][0] = sc;
                btr[ib] = 0;
            }
            if ((sc = xmx[cur][3] + hmm->xsc[3][0]) > xmx[cur][0]) {
                xmx[cur][0] = sc;
                btr[ib] = xtr[cur][3];
            }

            xmx[cur][2] = -987654321;
            if ((sc = xmx[prv][2] + hmm->xsc[2][1]) > -987654321) {
                xmx[cur][2] = sc;
                xtr[cur][2] = xtr[prv][2];
            }
            if ((sc = xmx[cur][1] + hmm->xsc[1][0]) > xmx[cur][2]) {
                xmx[cur][2] = sc;
                xtr[cur][2] = ib;
            }
        }
    }
}
