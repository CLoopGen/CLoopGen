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
for (i = 1; i <= L; i++) {
    cur = i % 2;
    prv = !cur;
    mmx[cur][0] = imx[cur][0] = dmx[cur][0] = -987654321;
    for (k = 1; k <= hmm->M; k++) {
        mmx[cur][k] = -987654321;
        if ((sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1]) > -987654321) {
            mmx[cur][k] = sc;
            mtr[cur][k] = mtr[prv][k - 1];
        }
        if ((sc = imx[prv][k - 1] + hmm->tsc[3][k - 1]) > mmx[cur][k]) {
            mmx[cur][k] = sc;
            mtr[cur][k] = itr[prv][k - 1];
        }
        if ((sc = xmx[prv][0] + hmm->bsc[k]) > mmx[cur][k]) {
            mmx[cur][k] = sc;
            mtr[cur][k] = i - 1;
        }
        if ((sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1]) > mmx[cur][k]) {
            mmx[cur][k] = sc;
            mtr[cur][k] = dtr[prv][k - 1];
        }
        if (hmm->msc[(int)dsq[i]][k] != -987654321)
            mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
        else
            mmx[cur][k] = -987654321;

        dmx[cur][k] = -987654321;
        if ((sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1]) > -987654321) {
            dmx[cur][k] = sc;
            dtr[cur][k] = mtr[cur][k - 1];
        }
        if ((sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1]) > dmx[cur][k]) {
            dmx[cur][k] = sc;
            dtr[cur][k] = dtr[cur][k - 1];
        }

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
    for (k = 1; k <= hmm->M; k++) {
        if ((sc = mmx[cur][k] + hmm->esc[k]) > xmx[cur][1]) {
            xmx[cur][1] = sc;
            etr[i] = mtr[cur][k];
        }
    }

    xmx[cur][3] = -987654321;
    if ((sc = xmx[prv][3] + hmm->xsc[3][1]) > -987654321) {
        xmx[cur][3] = sc;
        xtr[cur][3] = xtr[prv][3];
    }
    if ((sc = xmx[cur][1] + hmm->xsc[1][1]) > xmx[cur][3]) {
        xmx[cur][3] = sc;
        xtr[cur][3] = i;
    }

    xmx[cur][0] = -987654321;
    if ((sc = xmx[cur][4] + hmm->xsc[0][0]) > -987654321) {
        xmx[cur][0] = sc;
        btr[i] = 0;
    }
    if ((sc = xmx[cur][3] + hmm->xsc[3][0]) > xmx[cur][0]) {
        xmx[cur][0] = sc;
        btr[i] = xtr[cur][3];
    }

    xmx[cur][2] = -987654321;
    if ((sc = xmx[prv][2] + hmm->xsc[2][1]) > -987654321) {
        xmx[cur][2] = sc;
        xtr[cur][2] = xtr[prv][2];
    }
    if ((sc = xmx[cur][1] + hmm->xsc[1][0]) > xmx[cur][2]) {
        xmx[cur][2] = sc;
        xtr[cur][2] = i;
    }
}
}
