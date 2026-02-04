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



void loop(){
for (i = start + 1; i <= s2; i++) {
    cur = i % 2;
    prv = !cur;
    mmx[cur][k1] = imx[cur][k1] = dmx[cur][k1] = -987654321;
    if (k1 < hmm->M) {
        imx[cur][k1] = -987654321;
        int temp_sc1 = mmx[prv][k1] + hmm->tsc[1][k1];
        int temp_sc2 = imx[prv][k1] + hmm->tsc[4][k1];
        if (temp_sc1 > -987654321)
            imx[cur][k1] = temp_sc1;
        if (temp_sc2 > imx[cur][k1])
            imx[cur][k1] = temp_sc2;
        if (hmm->isc[(int)dsq[i]][k1] != -987654321)
            imx[cur][k1] += hmm->isc[(int)dsq[i]][k1];
        else
            imx[cur][k1] = -987654321;
    }
    int temp_bsc = xmx[prv][0] + hmm->bsc[k1];
    if (temp_bsc > -987654321)
        mmx[cur][k1] = temp_bsc;
    if (hmm->msc[(int)dsq[i]][k1] != -987654321)
        mmx[cur][k1] += hmm->msc[(int)dsq[i]][k1];
    else
        mmx[cur][k1] = -987654321;

    for (k = k1 + 1; k <= k3; k++) {
        mmx[cur][k] = -987654321;
        int mm_sc1 = mmx[prv][k - 1] + hmm->tsc[0][k - 1];
        int mm_sc2 = imx[prv][k - 1] + hmm->tsc[3][k - 1];
        int mm_sc3 = xmx[prv][0] + hmm->bsc[k];
        int mm_sc4 = dmx[prv][k - 1] + hmm->tsc[5][k - 1];
        if (mm_sc1 > -987654321) mmx[cur][k] = mm_sc1;
        if (mm_sc2 > mmx[cur][k]) mmx[cur][k] = mm_sc2;
        if (mm_sc3 > mmx[cur][k]) mmx[cur][k] = mm_sc3;
        if (mm_sc4 > mmx[cur][k]) mmx[cur][k] = mm_sc4;
        if (hmm->msc[(int)dsq[i]][k] != -987654321)
            mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
        else
            mmx[cur][k] = -987654321;

        dmx[cur][k] = -987654321;
        if (k < hmm->M) {
            int dm_sc1 = mmx[cur][k - 1] + hmm->tsc[2][k - 1];
            int dm_sc2 = dmx[cur][k - 1] + hmm->tsc[6][k - 1];
            if (dm_sc1 > -987654321) dmx[cur][k] = dm_sc1;
            if (dm_sc2 > dmx[cur][k]) dmx[cur][k] = dm_sc2;
        }

        imx[cur][k] = -987654321;
        if (k < hmm->M) {
            int im_sc1 = mmx[prv][k] + hmm->tsc[1][k];
            int im_sc2 = imx[prv][k] + hmm->tsc[4][k];
            if (im_sc1 > -987654321) imx[cur][k] = im_sc1;
            if (im_sc2 > imx[cur][k]) imx[cur][k] = im_sc2;
            if (hmm->isc[(int)dsq[i]][k] != -987654321)
                imx[cur][k] += hmm->isc[(int)dsq[i]][k];
            else
                imx[cur][k] = -987654321;
        }
    }

    xmx[cur][4] = -987654321;
    int x4_sc = xmx[prv][4] + hmm->xsc[0][1];
    if (x4_sc > -987654321)
        xmx[cur][4] = x4_sc;

    xmx[cur][1] = -987654321;
    for (k = k1; k <= k3 && k <= hmm->M; k++) {
        int x1_sc = mmx[cur][k] + hmm->esc[k];
        if (x1_sc > xmx[cur][1])
            xmx[cur][1] = x1_sc;
    }

    xmx[cur][0] = -987654321;
    int x0_sc = xmx[cur][4] + hmm->xsc[0][0];
    if (x0_sc > -987654321)
        xmx[cur][0] = x0_sc;

    xmx[cur][2] = -987654321;
    int x2_sc1 = xmx[prv][2] + hmm->xsc[2][1];
    int x2_sc2 = xmx[cur][1] + hmm->xsc[1][0];
    if (x2_sc1 > -987654321) xmx[cur][2] = x2_sc1;
    if (x2_sc2 > xmx[cur][2]) xmx[cur][2] = x2_sc2;
}
}
