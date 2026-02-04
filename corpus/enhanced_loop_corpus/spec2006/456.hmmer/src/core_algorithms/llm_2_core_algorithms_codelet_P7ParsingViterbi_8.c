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
    // Variant 1: Consecutive Memory Access via Array Restructuring (Structure of Arrays to Array of Structures-like access pattern)
    // We simulate a more cache-friendly, consecutive memory layout by accessing elements in a grouped manner.
    // Instead of scattered updates across mmx[cur][k], dmx[cur][k], etc., we group operations per state.

    for (i = 1; i <= L; i++) {
        cur = i % 2;
        prv = !cur;

        // Initialize current row with bulk assignment for better vectorization potential
        int *mmx_cur = mmx[cur];
        int *imx_cur = imx[cur];
        int *dmx_cur = dmx[cur];
        int *mtr_cur = mtr[cur];
        int *itr_cur = itr[cur];
        int *dtr_cur = dtr[cur];

        mmx_cur[0] = imx_cur[0] = dmx_cur[0] = -987654321;

        for (k = 1; k <= hmm->M; k++) {
            int *tsc_k1 = hmm->tsc[0]; // tsc[0][k-1]
            int *tsc_k2 = hmm->tsc[3]; // tsc[3][k-1]
            int *tsc_k3 = hmm->tsc[5]; // tsc[5][k-1]
            int *bsc_ptr = hmm->bsc;
            int *msc_row = hmm->msc[(int)dsq[i]];
            int *tsc_d1 = hmm->tsc[2]; // tsc[2][k-1]
            int *tsc_d2 = hmm->tsc[6]; // tsc[6][k-1]

            // Main M-state update using local references to reduce indexing overhead
            sc = -987654321;
            mmx_cur[k] = -987654321;

            int tmp_sc;
            if ((tmp_sc = mmx[prv][k - 1] + tsc_k1[k - 1]) > -987654321) {
                mmx_cur[k] = tmp_sc;
                mtr_cur[k] = mtr[prv][k - 1];
            }
            if ((tmp_sc = imx[prv][k - 1] + tsc_k2[k - 1]) > mmx_cur[k]) {
                mmx_cur[k] = tmp_sc;
                mtr_cur[k] = itr[prv][k - 1];
            }
            if ((tmp_sc = xmx[prv][0] + bsc_ptr[k]) > mmx_cur[k]) {
                mmx_cur[k] = tmp_sc;
                mtr_cur[k] = i - 1;
            }
            if ((tmp_sc = dmx[prv][k - 1] + tsc_k3[k - 1]) > mmx_cur[k]) {
                mmx_cur[k] = tmp_sc;
                mtr_cur[k] = dtr[prv][k - 1];
            }

            if (msc_row[k] != -987654321)
                mmx_cur[k] += msc_row[k];
            else
                mmx_cur[k] = -987654321;

            // D-state update
            dmx_cur[k] = -987654321;
            if ((tmp_sc = mmx_cur[k - 1] + tsc_d1[k - 1]) > -987654321) {
                dmx_cur[k] = tmp_sc;
                dtr_cur[k] = mtr_cur[k - 1];
            }
            if ((tmp_sc = dmx_cur[k - 1] + hmm->tsc[6][k - 1]) > dmx_cur[k]) {
                dmx_cur[k] = tmp_sc;
                dtr_cur[k] = dtr_cur[k - 1];
            }

            // I-state update (only if not last match state)
            if (k < hmm->M) {
                int *tsc_i1 = hmm->tsc[1];
                int *tsc_i2 = hmm->tsc[4];
                int *isc_row = hmm->isc[(int)dsq[i]];

                imx_cur[k] = -987654321;
                if ((tmp_sc = mmx[prv][k] + tsc_i1[k]) > -987654321) {
                    imx_cur[k] = tmp_sc;
                    itr_cur[k] = mtr[prv][k];
                }
                if ((tmp_sc = imx[prv][k] + tsc_i2[k]) > imx_cur[k]) {
                    imx_cur[k] = tmp_sc;
                    itr_cur[k] = itr[prv][k];
                }
                if (isc_row[k] != -987654321)
                    imx_cur[k] += isc_row[k];
                else
                    imx_cur[k] = -987654321;
            }
        }

        // X-state updates with direct indexing and reduced aliasing
        int *xmx_cur = xmx[cur];
        int *xmx_prv = xmx[prv];
        int (*xsc)[2] = hmm->xsc;

        xmx_cur[4] = -987654321;
        if ((sc = xmx_prv[4] + xsc[0][1]) > -987654321)
            xmx_cur[4] = sc;

        xmx_cur[1] = -987654321;
        for (k = 1; k <= hmm->M; k++) {
            if ((sc = mmx_cur[k] + hmm->esc[k]) > xmx_cur[1]) {
                xmx_cur[1] = sc;
                etr[i] = mtr_cur[k];
            }
        }

        xmx_cur[3] = -987654321;
        if ((sc = xmx_prv[3] + xsc[3][1]) > -987654321) {
            xmx_cur[3] = sc;
            xtr[cur][3] = xtr[prv][3];
        }
        if ((sc = xmx_cur[1] + xsc[1][1]) > xmx_cur[3]) {
            xmx_cur[3] = sc;
            xtr[cur][3] = i;
        }

        xmx_cur[0] = -987654321;
        if ((sc = xmx_cur[4] + xsc[0][0]) > -987654321) {
            xmx_cur[0] = sc;
            btr[i] = 0;
        }
        if ((sc = xmx_cur[3] + xsc[3][0]) > xmx_cur[0]) {
            xmx_cur[0] = sc;
            btr[i] = xtr[cur][3];
        }

        xmx_cur[2] = -987654321;
        if ((sc = xmx_prv[2] + xsc[2][1]) > -987654321) {
            xmx_cur[2] = sc;
            xtr[cur][2] = xtr[prv][2];
        }
        if ((sc = xmx_cur[1] + xsc[1][0]) > xmx_cur[2]) {
            xmx_cur[2] = sc;
            xtr[cur][2] = i;
        }
    }
}
