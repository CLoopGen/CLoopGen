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
        if ((sc = mmx[prv][k1] + hmm->tsc[1][k1]) > -987654321)
            imx[cur][k1] = sc;
        if ((sc = imx[prv][k1] + hmm->tsc[4][k1]) > imx[cur][k1])
            imx[cur][k1] = sc;
        if (hmm->isc[(int)dsq[i]][k1] != -987654321)
            imx[cur][k1] += hmm->isc[(int)dsq[i]][k1];
        else
            imx[cur][k1] = -987654321;
    }
    if ((sc = xmx[prv][0] + hmm->bsc[k1]) > -987654321)
        mmx[cur][k1] = sc;
    if (hmm->msc[(int)dsq[i]][k1] != -987654321)
        mmx[cur][k1] += hmm->msc[(int)dsq[i]][k1];
    else
        mmx[cur][k1] = -987654321;

    for (k = k1 + 1; k <= k3; k++) {
        mmx[cur][k] = -987654321;
        if ((sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1]) > -987654321)
            mmx[cur][k] = sc;
        if ((sc = imx[prv][k - 1] + hmm->tsc[3][k - 1]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if ((sc = xmx[prv][0] + hmm->bsc[k]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if ((sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if (hmm->msc[(int)dsq[i]][k] != -987654321)
            mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
        else
            mmx[cur][k] = -987654321;

        dmx[cur][k] = -987654321;
        if (k < hmm->M) {
            if ((sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1]) > -987654321)
                dmx[cur][k] = sc;
            if ((sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1]) > dmx[cur][k])
                dmx[cur][k] = sc;
        }

        imx[cur][k] = -987654321;
        if (k < hmm->M) {
            if ((sc = mmx[prv][k] + hmm->tsc[1][k]) > -987654321)
                imx[cur][k] = sc;
            if ((sc = imx[prv][k] + hmm->tsc[4][k]) > imx[cur][k])
                imx[cur][k] = sc;
            if (hmm->isc[(int)dsq[i]][k] != -987654321)
                imx[cur][k] += hmm->isc[(int)dsq[i]][k];
            else
                imx[cur][k] = -987654321;
        }
    }

    xmx[cur][4] = -987654321;
    if ((sc = xmx[prv][4] + hmm->xsc[0][1]) > -987654321)
        xmx[cur][4] = sc;

    xmx[cur][1] = -987654321;
    for (k = k1; k <= k3 && k <= hmm->M; k++)
        if ((sc = mmx[cur][k] + hmm->esc[k]) > xmx[cur][1])
            xmx[cur][1] = sc;

    xmx[cur][0] = -987654321;
    if ((sc = xmx[cur][4] + hmm->xsc[0][0]) > -987654321)
        xmx[cur][0] = sc;

    xmx[cur][2] = -987654321;
    if ((sc = xmx[prv][2] + hmm->xsc[2][1]) > -987654321)
        xmx[cur][2] = sc;
    if ((sc = xmx[cur][1] + hmm->xsc[1][0]) > xmx[cur][2])
        xmx[cur][2] = sc;
}
}
