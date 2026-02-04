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



void loop() {
    for (i = start + 1; i <= s2; i++) {
        cur = i % 2;
        prv = !cur;
        mmx[cur][k1] = imx[cur][k1] = dmx[cur][k1] = -987654321;

        if (k1 < hmm->M) {
            imx[cur][k1] = -987654321;
            int temp_sc1 = mmx[prv][k1] + hmm->tsc[1][k1];
            int temp_sc2 = imx[prv][k1] + hmm->tsc[4][k1];
            if (temp_sc1 > -987654321) imx[cur][k1] = temp_sc1;
            if (temp_sc2 > imx[cur][k1]) imx[cur][k1] = temp_sc2;
            int issc = hmm->isc[(int)dsq[i]][k1];
            if (issc != -987654321) imx[cur][k1] += issc;
            else imx[cur][k1] = -987654321;
        }

        int xbsc = xmx[prv][0] + hmm->bsc[k1];
        if (xbsc > -987654321) mmx[cur][k1] = xbsc;
        else mmx[cur][k1] = -987654321;

        int msc_val = hmm->msc[(int)dsq[i]][k1];
        if (msc_val != -987654321 && mmx[cur][k1] != -987654321)
            mmx[cur][k1] += msc_val;
        else
            mmx[cur][k1] = -987654321;

        for (k = k1 + 1; k <= k3; k++) {
            mmx[cur][k] = -987654321;
            int mm_transitions[4];
            mm_transitions[0] = mmx[prv][k - 1] + hmm->tsc[0][k - 1];
            mm_transitions[1] = imx[prv][k - 1] + hmm->tsc[3][k - 1];
            mm_transitions[2] = xmx[prv][0] + hmm->bsc[k];
            mm_transitions[3] = dmx[prv][k - 1] + hmm->tsc[5][k - 1];

            for (int t = 0; t < 4; t++)
                if (mm_transitions[t] > mmx[cur][k])
                    mmx[cur][k] = mm_transitions[t];

            msc_val = hmm->msc[(int)dsq[i]][k];
            if (msc_val != -987654321 && mmx[cur][k] != -987654321)
                mmx[cur][k] += msc_val;
            else
                mmx[cur][k] = -987654321;

            dmx[cur][k] = -987654321;
            if (k < hmm->M) {
                int d_trans1 = mmx[cur][k - 1] + hmm->tsc[2][k - 1];
                int d_trans2 = dmx[cur][k - 1] + hmm->tsc[6][k - 1];
                if (d_trans1 > -987654321) dmx[cur][k] = d_trans1;
                if (d_trans2 > dmx[cur][k]) dmx[cur][k] = d_trans2;
            }

            imx[cur][k] = -987654321;
            if (k < hmm->M) {
                int i_trans1 = mmx[prv][k] + hmm->tsc[1][k];
                int i_trans2 = imx[prv][k] + hmm->tsc[4][k];
                if (i_trans1 > -987654321) imx[cur][k] = i_trans1;
                if (i_trans2 > imx[cur][k]) imx[cur][k] = i_trans2;
                int isc_val = hmm->isc[(int)dsq[i]][k];
                if (isc_val != -987654321) imx[cur][k] += isc_val;
                else imx[cur][k] = -987654321;
            }
        }

        xmx[cur][4] = -987654321;
        int x4sc = xmx[prv][4] + hmm->xsc[0][1];
        if (x4sc > -987654321) xmx[cur][4] = x4sc;

        xmx[cur][1] = -987654321;
        for (k = k1; k <= k3 && k <= hmm->M; k++) {
            int esc_contrib = mmx[cur][k] + hmm->esc[k];
            if (esc_contrib > xmx[cur][1]) xmx[cur][1] = esc_contrib;
        }

        xmx[cur][0] = -987654321;
        int x0sc = xmx[cur][4] + hmm->xsc[0][0];
        if (x0sc > -987654321) xmx[cur][0] = x0sc;

        xmx[cur][2] = -987654321;
        int x2sc1 = xmx[prv][2] + hmm->xsc[2][1];
        int x2sc2 = xmx[cur][1] + hmm->xsc[1][0];
        if (x2sc1 > -987654321) xmx[cur][2] = x2sc1;
        if (x2sc2 > xmx[cur][2]) xmx[cur][2] = x2sc2;
    }
}
