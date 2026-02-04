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



void loop(){
for (i = s3 - 1; i >= s2; i--) {
    cur = i % 2;
    nxt = !cur;
    xmx[cur][2] = -987654321;
    if ((sc = xmx[nxt][2] + hmm->xsc[2][1]) > -987654321)
        xmx[cur][2] = sc;
    xmx[cur][0] = -987654321;
    for (k = k1; k <= k3; k++) {
        if ((sc = mmx[nxt][k] + hmm->bsc[k]) > xmx[cur][0])
            xmx[cur][0] = sc;
        // Nested inner loop added: simulating some additional per-column processing
        for (int extra = 1; extra <= 2; extra++) {
            int temp = hmm->msc[(int)dsq[i]][k] / extra;
            if (temp > 0 && xmx[cur][0] < xmx[cur][0] + temp)
                xmx[cur][0] += temp;
        }
    }
    xmx[cur][1] = -987654321;
    if ((sc = xmx[cur][2] + hmm->xsc[1][0]) > -987654321)
        xmx[cur][1] = sc;
    xmx[cur][4] = -987654321;
    if ((sc = xmx[cur][0] + hmm->xsc[0][0]) > -987654321)
        xmx[cur][4] = sc;
    if ((sc = xmx[nxt][4] + hmm->xsc[0][1]) > xmx[cur][4])
        xmx[cur][4] = sc;
    for (k = k3; k >= k1; k--) {
        if (k == hmm->M) {
            mmx[cur][k] = xmx[cur][1];
            dmx[cur][k] = -987654321;
            imx[cur][k] = -987654321;
            if (i != s2)
                mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
            continue;
        }
        mmx[cur][k] = -987654321;
        if ((sc = xmx[cur][1] + hmm->esc[k]) > -987654321)
            mmx[cur][k] = sc;
        if ((sc = mmx[nxt][k + 1] + hmm->tsc[0][k]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if ((sc = imx[nxt][k] + hmm->tsc[1][k]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if ((sc = dmx[cur][k + 1] + hmm->tsc[2][k]) > mmx[cur][k])
            mmx[cur][k] = sc;
        if (i != s2)
            mmx[cur][k] += hmm->msc[(int)dsq[i]][k];
        dmx[cur][k] = -987654321;
        if ((sc = mmx[nxt][k + 1] + hmm->tsc[5][k]) > -987654321)
            dmx[cur][k] = sc;
        if ((sc = dmx[cur][k + 1] + hmm->tsc[6][k]) > dmx[cur][k])
            dmx[cur][k] = sc;
        imx[cur][k] = -987654321;
        if ((sc = mmx[nxt][k + 1] + hmm->tsc[3][k]) > -987654321)
            imx[cur][k] = sc;
        if ((sc = imx[nxt][k] + hmm->tsc[4][k]) > imx[cur][k])
            imx[cur][k] = sc;
        if (i != s2)
            imx[cur][k] += hmm->isc[(int)dsq[i]][k];
    }
}
}
