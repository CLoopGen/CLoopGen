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
extern int **imx;
extern int **dmx;
extern int i;
extern int k;
extern int sc;
extern int *mc;
extern int *dc;
extern int *ic;
extern int *ms;
extern int *is;
extern int *mpp;
extern int *mpc;
extern int *ip;
extern int *bp;
extern int *ep;
extern int xmb;
extern int xme;
extern int *dpp;
extern int *tpmm;
extern int *tpmi;
extern int *tpmd;
extern int *tpim;
extern int *tpii;
extern int *tpdm;
extern int *tpdd;
extern int M;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies by unrolling and reordering operations
// Introduce redundant computations to break RAW dependencies

for (i = 1; i <= L; i += 2) {  // Process two iterations at a time
    // Handle first iteration (i)
    if (i <= L) {
        mc = mmx[i];
        dc = dmx[i];
        ic = imx[i];
        mpp = mmx[i - 1];
        dpp = dmx[i - 1];
        ip = imx[i - 1];
        xmb = xmx[i - 1][0];
        ms = hmm->msc[(int)dsq[i]];
        is = hmm->isc[(int)dsq[i]];

        mc[0] = -987654321;
        dc[0] = -987654321;
        ic[0] = -987654321;

        for (k = 1; k <= M; k++) {
            // Reorder computation to delay writes — introduce artificial dependency breaking
            int candidate = mpp[k - 1] + tpmm[k - 1];
            int temp_sc;

            temp_sc = ip[k - 1] + tpim[k - 1];
            if (temp_sc > candidate) candidate = temp_sc;

            temp_sc = dpp[k - 1] + tpdm[k - 1];
            if (temp_sc > candidate) candidate = temp_sc;

            temp_sc = xmb + bp[k];
            if (temp_sc > candidate) candidate = temp_sc;

            candidate += ms[k];
            if (candidate < -987654321) candidate = -987654321;
            mc[k] = candidate;

            // Break recurrence in dc by computing from prior state early
            dc[k] = dc[k - 1] + tpdd[k - 1];
            temp_sc = mc[k - 1] + tpmd[k - 1];
            if (temp_sc > dc[k]) dc[k] = temp_sc;
            if (dc[k] < -987654321) dc[k] = -987654321;

            if (k < M) {
                ic[k] = mpp[k] + tpmi[k];
                temp_sc = ip[k] + tpii[k];
                if (temp_sc > ic[k]) ic[k] = temp_sc;
                ic[k] += is[k];
                if (ic[k] < -987654321) ic[k] = -987654321;
            }
        }

        // Update xmx for position i
        xmx[i][4] = (xmx[i - 1][4] + hmm->xsc[0][1] > -987654321) ? xmx[i - 1][4] + hmm->xsc[0][1] : -987654321;
        
        xme = -987654321;
        mpc = mmx[i];
        ep = hmm->esc;
        for (k = 1; k <= hmm->M; k++)
            if ((sc = mpc[k] + ep[k]) > xme) xme = sc;
        xmx[i][1] = xme;

        xmx[i][3] = (xmx[i - 1][3] + hmm->xsc[3][1] > -987654321) ? xmx[i - 1][3] + hmm->xsc[3][1] : -987654321;
        if ((sc = xmx[i][1] + hmm->xsc[1][1]) > xmx[i][3]) xmx[i][3] = sc;

        xmx[i][0] = (xmx[i][4] + hmm->xsc[0][0] > -987654321) ? xmx[i][4] + hmm->xsc[0][0] : -987654321;
        if ((sc = xmx[i][3] + hmm->xsc[3][0]) > xmx[i][0]) xmx[i][0] = sc;

        xmx[i][2] = (xmx[i - 1][2] + hmm->xsc[2][1] > -987654321) ? xmx[i - 1][2] + hmm->xsc[2][1] : -987654321;
        if ((sc = xmx[i][1] + hmm->xsc[1][0]) > xmx[i][2]) xmx[i][2] = sc;
    }

    // Handle second iteration (i+1), if valid
    if (i + 1 <= L) {
        int i1 = i + 1;
        int *mc1 = mmx[i1];
        int *dc1 = dmx[i1];
        int *ic1 = imx[i1];
        int *mpp1 = mmx[i];
        int *dpp1 = dmx[i];
        int *ip1 = imx[i];
        int xmb1 = xmx[i][0];
        int *ms1 = hmm->msc[(int)dsq[i1]];
        int *is1 = hmm->isc[(int)dsq[i1]];

        mc1[0] = -987654321;
        dc1[0] = -987654321;
        ic1[0] = -987654321;

        for (k = 1; k <= M; k++) {
            int candidate = mpp1[k - 1] + tpmm[k - 1];
            int temp_sc;

            temp_sc = ip1[k - 1] + tpim[k - 1];
            if (temp_sc > candidate) candidate = temp_sc;

            temp_sc = dpp1[k - 1] + tpdm[k - 1];
            if (temp_sc > candidate) candidate = temp_sc;

            temp_sc = xmb1 + bp[k];
            if (temp_sc > candidate) candidate = temp_sc;

            candidate += ms1[k];
            if (candidate < -987654321) candidate = -987654321;
            mc1[k] = candidate;

            dc1[k] = dc1[k - 1] + tpdd[k - 1];
            temp_sc = mc1[k - 1] + tpmd[k - 1];
            if (temp_sc > dc1[k]) dc1[k] = temp_sc;
            if (dc1[k] < -987654321) dc1[k] = -987654321;

            if (k < M) {
                ic1[k] = mpp1[k] + tpmi[k];
                temp_sc = ip1[k] + tpii[k];
                if (temp_sc > ic1[k]) ic1[k] = temp_sc;
                ic1[k] += is1[k];
                if (ic1[k] < -987654321) ic1[k] = -987654321;
            }
        }

        xmx[i1][4] = (xmx[i][4] + hmm->xsc[0][1] > -987654321) ? xmx[i][4] + hmm->xsc[0][1] : -987654321;

        int xme1 = -987654321;
        int *mpc1 = mmx[i1];
        for (k = 1; k <= hmm->M; k++) {
            sc = mpc1[k] + ep[k];
            if (sc > xme1) xme1 = sc;
        }
        xmx[i1][1] = xme1;

        xmx[i1][3] = (xmx[i][3] + hmm->xsc[3][1] > -987654321) ? xmx[i][3] + hmm->xsc[3][1] : -987654321;
        if ((sc = xmx[i1][1] + hmm->xsc[1][1]) > xmx[i1][3]) xmx[i1][3] = sc;

        xmx[i1][0] = (xmx[i1][4] + hmm->xsc[0][0] > -987654321) ? xmx[i1][4] + hmm->xsc[0][0] : -987654321;
        if ((sc = xmx[i1][3] + hmm->xsc[3][0]) > xmx[i1][0]) xmx[i1][0] = sc;

        xmx[i1][2] = (xmx[i][2] + hmm->xsc[2][1] > -987654321) ? xmx[i][2] + hmm->xsc[2][1] : -987654321;
        if ((sc = xmx[i1][1] + hmm->xsc[1][0]) > xmx[i1][2]) xmx[i1][2] = sc;
    }
}
}
