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
extern int codon;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase loop nesting depth by splitting the inner logic into multiple layered loops
for (i = 2; i <= L; i++) {
    mmx[i][0] = imx[i][0] = dmx[i][0] = -987654321;
    if (i > 2) {
        if (dsq[i - 2] < 4 && dsq[i - 1] < 4 && dsq[i] < 4)
            codon = dsq[i - 2] * 16 + dsq[i - 1] * 4 + dsq[i];
        else
            codon = 64;
    }

    // First pass: Update mmx values using k-loop
    for (k = 1; k <= hmm->M; k++) {
        if (i > 2) {
            mmx[i][k] = mmx[i - 3][k - 1] + hmm->tsc[0][k - 1];
            if ((sc = imx[i - 3][k - 1] + hmm->tsc[3][k - 1]) > mmx[i][k])
                mmx[i][k] = sc;
            if ((sc = xmx[i - 3][0] + hmm->bsc[k]) > mmx[i][k])
                mmx[i][k] = sc;
            if ((sc = dmx[i - 3][k - 1] + hmm->tsc[5][k - 1]) > mmx[i][k])
                mmx[i][k] = sc;
            mmx[i][k] += hmm->dnam[codon][k];
        }
        if ((sc = mmx[i - 2][k - 1] + hmm->tsc[0][k - 1] + hmm->dna2) > mmx[i][k])
            mmx[i][k] = sc;
        if ((sc = imx[i - 2][k - 1] + hmm->tsc[3][k - 1] + hmm->dna2) > mmx[i][k])
            mmx[i][k] = sc;
        if ((sc = xmx[i - 2][0] + hmm->bsc[k] + hmm->dna2) > mmx[i][k])
            mmx[i][k] = sc;
        if ((sc = dmx[i - 2][k - 1] + hmm->tsc[5][k - 1] + hmm->dna2) > mmx[i][k])
            mmx[i][k] = sc;
        if (i > 3) {
            if ((sc = mmx[i - 4][k - 1] + hmm->tsc[0][k - 1] + hmm->dna4) > mmx[i][k])
                mmx[i][k] = sc;
            if ((sc = imx[i - 4][k - 1] + hmm->tsc[3][k - 1] + hmm->dna4) > mmx[i][k])
                mmx[i][k] = sc;
            if ((sc = xmx[i - 4][0] + hmm->bsc[k] + hmm->dna4) > mmx[i][k])
                mmx[i][k] = sc;
            if ((sc = dmx[i - 4][k - 1] + hmm->tsc[5][k - 1] + hmm->dna4) > mmx[i][k])
                mmx[i][k] = sc;
        }
    }

    // Second pass: Update dmx and imx in separate nested loops to deepen structure
    for (k = 1; k <= hmm->M; k++) {
        dmx[i][k] = mmx[i][k - 1] + hmm->tsc[2][k - 1];
        if ((sc = dmx[i][k - 1] + hmm->tsc[6][k - 1]) > dmx[i][k])
            dmx[i][k] = sc;
    }

    for (k = 1; k <= hmm->M; k++) {
        if (i > 2) {
            imx[i][k] = mmx[i - 3][k] + hmm->tsc[1][k];
            if ((sc = imx[i - 3][k] + hmm->tsc[4][k]) > imx[i][k])
                imx[i][k] = sc;
            imx[i][k] += hmm->dnai[codon][k];
        }
        if ((sc = mmx[i - 2][k] + hmm->tsc[1][k] + hmm->dna2) > imx[i][k])
            imx[i][k] = sc;
        if ((sc = imx[i - 2][k] + hmm->tsc[4][k] + hmm->dna2) > imx[i][k])
            imx[i][k] = sc;
        if (i > 4) {
            if ((sc = mmx[i - 4][k] + hmm->tsc[1][k] + hmm->dna4) > imx[i][k])
                imx[i][k] = sc;
            if ((sc = imx[i - 4][k] + hmm->tsc[4][k] + hmm->dna4) > imx[i][k])
                imx[i][k] = sc;
        }
    }

    // Final pass: Update xmx array with additional nesting for state transitions
    xmx[i][4] = xmx[i - 1][4] + hmm->xsc[0][1];
    xmx[i][1] = dmx[i][hmm->M];
    for (k = 1; k <= hmm->M; k++) {
        if ((sc = mmx[i][k] + hmm->esc[k]) > xmx[i][1])
            xmx[i][1] = sc;
    }
    xmx[i][3] = xmx[i - 1][3] + hmm->xsc[3][1];
    if ((sc = xmx[i][1] + hmm->xsc[1][1]) > xmx[i][3])
        xmx[i][3] = sc;
    xmx[i][0] = xmx[i][4] + hmm->xsc[0][0];
    if ((sc = xmx[i][3] + hmm->xsc[3][0]) > xmx[i][0])
        xmx[i][0] = sc;
    xmx[i][2] = xmx[i - 1][2] + hmm->xsc[2][1];
    if ((sc = xmx[i][1] + hmm->xsc[1][0]) > xmx[i][2])
        xmx[i][2] = sc;
}
}
