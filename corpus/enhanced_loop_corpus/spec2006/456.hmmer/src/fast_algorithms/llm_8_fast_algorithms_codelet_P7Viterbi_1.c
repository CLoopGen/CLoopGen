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



void loop() {
    for (i = 1; i <= L; i += 2) {
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

        if (i + 1 <= L) {
            int *next_mc = mmx[i + 1];
            int *next_dc = dmx[i + 1];
            int *next_ic = imx[i + 1];
            int *next_mpp = mmx[i];
            int *next_dpp = dmx[i];
            int *next_ip = imx[i];
            int next_xmb = xmx[i][0];
            int *next_ms = hmm->msc[(int)dsq[i + 1]];
            int *next_is = hmm->isc[(int)dsq[i + 1]];

            next_mc[0] = -987654321;
            next_dc[0] = -987654321;
            next_ic[0] = -987654321;
        }

        for (k = 1; k <= M; k++) {
            mc[k] = mpp[k - 1] + tpmm[k - 1];
            sc = ip[k - 1] + tpim[k - 1];
            if (sc > mc[k]) mc[k] = sc;
            sc = dpp[k - 1] + tpdm[k - 1];
            if (sc > mc[k]) mc[k] = sc;
            sc = xmb + bp[k];
            if (sc > mc[k]) mc[k] = sc;
            mc[k] += ms[k];
            if (mc[k] < -987654321) mc[k] = -987654321;

            dc[k] = dc[k - 1] + tpdd[k - 1];
            sc = mc[k - 1] + tpmd[k - 1];
            if (sc > dc[k]) dc[k] = sc;
            if (dc[k] < -987654321) dc[k] = -987654321;

            if (k < M) {
                ic[k] = mpp[k] + tpmi[k];
                sc = ip[k] + tpii[k];
                if (sc > ic[k]) ic[k] = sc;
                ic[k] += is[k];
                if (ic[k] < -987654321) ic[k] = -987654321;
            }
        }

        xmx[i][4] = -987654321;
        sc = xmx[i - 1][4] + hmm->xsc[0][1];
        if (sc > -987654321) xmx[i][4] = sc;

        xme = -987654321;
        mpc = mmx[i];
        ep = hmm->esc;
        for (k = 1; k <= hmm->M; k++) {
            sc = mpc[k] + ep[k];
            if (sc > xme) xme = sc;
        }
        xmx[i][1] = xme;

        xmx[i][3] = -987654321;
        sc = xmx[i - 1][3] + hmm->xsc[3][1];
        if (sc > -987654321) xmx[i][3] = sc;
        sc = xmx[i][1] + hmm->xsc[1][1];
        if (sc > xmx[i][3]) xmx[i][3] = sc;

        xmx[i][0] = -987654321;
        sc = xmx[i][4] + hmm->xsc[0][0];
        if (sc > -987654321) xmx[i][0] = sc;
        sc = xmx[i][3] + hmm->xsc[3][0];
        if (sc > xmx[i][0]) xmx[i][0] = sc;

        xmx[i][2] = -987654321;
        sc = xmx[i - 1][2] + hmm->xsc[2][1];
        if (sc > -987654321) xmx[i][2] = sc;
        sc = xmx[i][1] + hmm->xsc[1][0];
        if (sc > xmx[i][2]) xmx[i][2] = sc;

        if (i + 1 <= L) {
            int *next_mc = mmx[i + 1];
            int *next_dc = dmx[i + 1];
            int *next_ic = imx[i + 1];
            int *next_mpp = mmx[i];
            int *next_dpp = dmx[i];
            int *next_ip = imx[i];
            int next_xmb = xmx[i][0];
            int *next_ms = hmm->msc[(int)dsq[i + 1]];
            int *next_is = hmm->isc[(int)dsq[i + 1]];

            next_mc[0] = -987654321;
            next_dc[0] = -987654321;
            next_ic[0] = -987654321;

            for (int kk = 1; kk <= M; kk++) {
                next_mc[kk] = next_mpp[kk - 1] + tpmm[kk - 1];
                sc = next_ip[kk - 1] + tpim[kk - 1];
                if (sc > next_mc[kk]) next_mc[kk] = sc;
                sc = next_dpp[kk - 1] + tpdm[kk - 1];
                if (sc > next_mc[kk]) next_mc[kk] = sc;
                sc = next_xmb + bp[kk];
                if (sc > next_mc[kk]) next_mc[kk] = sc;
                next_mc[kk] += next_ms[kk];
                if (next_mc[kk] < -987654321) next_mc[kk] = -987654321;

                next_dc[kk] = next_dc[kk - 1] + tpdd[kk - 1];
                sc = next_mc[kk - 1] + tpmd[kk - 1];
                if (sc > next_dc[kk]) next_dc[kk] = sc;
                if (next_dc[kk] < -987654321) next_dc[kk] = -987654321;

                if (kk < M) {
                    next_ic[kk] = next_mpp[kk] + tpmi[kk];
                    sc = next_ip[kk] + tpii[kk];
                    if (sc > next_ic[kk]) next_ic[kk] = sc;
                    next_ic[kk] += next_is[kk];
                    if (next_ic[kk] < -987654321) next_ic[kk] = -987654321;
                }
            }

            xmx[i + 1][4] = -987654321;
            sc = xmx[i][4] + hmm->xsc[0][1];
            if (sc > -987654321) xmx[i + 1][4] = sc;

            int next_xme = -987654321;
            int *next_mpc = mmx[i + 1];
            for (int kk = 1; kk <= hmm->M; kk++) {
                sc = next_mpc[kk] + ep[kk];
                if (sc > next_xme) next_xme = sc;
            }
            xmx[i + 1][1] = next_xme;

            xmx[i + 1][3] = -987654321;
            sc = xmx[i][3] + hmm->xsc[3][1];
            if (sc > -987654321) xmx[i + 1][3] = sc;
            sc = xmx[i + 1][1] + hmm->xsc[1][1];
            if (sc > xmx[i + 1][3]) xmx[i + 1][3] = sc;

            xmx[i + 1][0] = -987654321;
            sc = xmx[i + 1][4] + hmm->xsc[0][0];
            if (sc > -987654321) xmx[i + 1][0] = sc;
            sc = xmx[i + 1][3] + hmm->xsc[3][0];
            if (sc > xmx[i + 1][0]) xmx[i + 1][0] = sc;

            xmx[i + 1][2] = -987654321;
            sc = xmx[i][2] + hmm->xsc[2][1];
            if (sc > -987654321) xmx[i + 1][2] = sc;
            sc = xmx[i + 1][1] + hmm->xsc[1][0];
            if (sc > xmx[i + 1][2]) xmx[i + 1][2] = sc;
        }
    }
}
