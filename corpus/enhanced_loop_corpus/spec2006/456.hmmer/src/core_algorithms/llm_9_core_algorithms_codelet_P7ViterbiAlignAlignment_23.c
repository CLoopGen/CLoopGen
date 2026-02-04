#include <stdio.h>

#include <inttypes.h>

struct gki_elem {
    char *key;
    int idx;
    struct gki_elem *nxt;
};


typedef struct {
    struct gki_elem **table;
    int primelevel;
    int nhash;
    int nkeys;
} GKI;

typedef struct msa_struct {
    char **aseq;
    char **sqname;
    float *wgt;
    int alen;
    int nseq;
    int flags;
    int type;
    char *name;
    char *desc;
    char *acc;
    char *au;
    char *ss_cons;
    char *sa_cons;
    char *rf;
    char **sqacc;
    char **sqdesc;
    char **ss;
    char **sa;
    float cutoff[6];
    int cutoff_is_set[6];
    char **comment;
    int ncomment;
    int alloc_ncomment;
    char **gf_tag;
    char **gf;
    int ngf;
    int alloc_ngf;
    char **gs_tag;
    char ***gs;
    GKI *gs_idx;
    int ngs;
    char **gc_tag;
    char **gc;
    GKI *gc_idx;
    int ngc;
    char **gr_tag;
    char ***gr;
    GKI *gr_idx;
    int ngr;
    GKI *index;
    int nseqalloc;
    int nseqlump;
    int *sqlen;
    int *sslen;
    int *salen;
    int lastidx;
} MSA;

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


struct dpshadow_s {
    char **xtb;
    char **mtb;
    char **itb;
    char **dtb;
    int *esrc;
};


extern int Alphabet_size;
extern MSA *msa;
extern struct plan7_s *hmm;
extern struct dpshadow_s *tb;
extern int **xmx;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern char **xtb;
extern char **mtb;
extern char **itb;
extern char **dtb;
extern float **con;
extern float *mocc;
extern int i;
extern int k;
extern int sym;
extern int sc;
extern int cur;
extern int prv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (i = 1; i <= msa->alen; i += step) {
    for (int offset = 0; offset < step && (i + offset) <= msa->alen; ++offset) {
        int ii = i + offset;
        int cur_local = ii % 2;
        int prv_local = !cur_local;
        mmx[cur_local][0] = imx[cur_local][0] = dmx[cur_local][0] = -987654321;
        mtb[ii][0] = itb[ii][0] = dtb[ii][0] = 0;
        for (k = 1; k <= hmm->M; k++) {
            mmx[cur_local][k] = -987654321;
            mtb[ii][k] = 0;
            if (mmx[prv_local][k - 1] > -987654321 && hmm->tsc[0][k - 1] > -987654321) {
                sc = mmx[prv_local][k - 1] + hmm->tsc[0][k - 1];
                if (sc > mmx[cur_local][k]) {
                    mmx[cur_local][k] = sc;
                    mtb[ii][k] = 1;
                }
            }
            if (imx[prv_local][k - 1] > -987654321 && hmm->tsc[3][k - 1] > -987654321) {
                sc = imx[prv_local][k - 1] + hmm->tsc[3][k - 1] * mocc[ii - 1];
                if (sc > mmx[cur_local][k]) {
                    mmx[cur_local][k] = sc;
                    mtb[ii][k] = 3;
                }
            }
            sc = xmx[prv_local][0] + hmm->bsc[k];
            if (sc > mmx[cur_local][k]) {
                mmx[cur_local][k] = sc;
                mtb[ii][k] = 6;
            }
            if (dmx[prv_local][k - 1] > -987654321 && hmm->tsc[5][k - 1] > -987654321) {
                sc = dmx[prv_local][k - 1] + hmm->tsc[5][k - 1];
                if (sc > mmx[cur_local][k]) {
                    mmx[cur_local][k] = sc;
                    mtb[ii][k] = 2;
                }
            }
            for (sym = 0; sym < Alphabet_size; sym++) {
                if (con[ii][sym] > 0 && hmm->msc[sym][k] == -987654321) {
                    mmx[cur_local][k] = -987654321;
                    break;
                }
                mmx[cur_local][k] += hmm->msc[sym][k] * con[ii][sym];
            }
            dmx[cur_local][k] = -987654321;
            dtb[ii][k] = 0;
            if (mmx[cur_local][k - 1] > -987654321 && hmm->tsc[2][k - 1] > -987654321) {
                sc = mmx[cur_local][k - 1] + hmm->tsc[2][k - 1];
                if (sc > dmx[cur_local][k]) {
                    dmx[cur_local][k] = sc;
                    dtb[ii][k] = 1;
                }
            }
            if (dmx[cur_local][k - 1] > -987654321 && hmm->tsc[6][k - 1] > -987654321) {
                sc = dmx[cur_local][k - 1] + hmm->tsc[6][k - 1];
                if (sc > dmx[cur_local][k]) {
                    dmx[cur_local][k] = sc;
                    dtb[ii][k] = 2;
                }
            }
            if (k < hmm->M) {
                imx[cur_local][k] = -987654321;
                itb[ii][k] = 0;
                if (mmx[prv_local][k] > -987654321 && hmm->tsc[1][k] > -987654321) {
                    sc = mmx[prv_local][k] + hmm->tsc[1][k] * mocc[ii];
                    if (sc > imx[cur_local][k]) {
                        imx[cur_local][k] = sc;
                        itb[ii][k] = 1;
                    }
                }
                if (imx[prv_local][k] > -987654321 && hmm->tsc[4][k] > -987654321) {
                    sc = imx[prv_local][k] + hmm->tsc[4][k] * mocc[ii - 1] * mocc[ii];
                    if (sc > imx[cur_local][k]) {
                        imx[cur_local][k] = sc;
                        itb[ii][k] = 3;
                    }
                }
                for (sym = 0; sym < Alphabet_size; sym++) {
                    if (con[ii][sym] > 0 && hmm->isc[sym][k] == -987654321) {
                        imx[cur_local][k] = -987654321;
                        break;
                    }
                    imx[cur_local][k] += hmm->isc[sym][k] * con[ii][sym];
                }
            }
        }
        xmx[cur_local][4] = -987654321;
        xtb[ii][4] = 0;
        if (xmx[prv_local][4] > -987654321 && hmm->xsc[0][1] > -987654321) {
            sc = xmx[prv_local][4] + hmm->xsc[0][1] * mocc[ii];
            if (sc > -987654321) {
                xmx[cur_local][4] = sc;
                xtb[ii][4] = 5;
            }
        }
        xmx[cur_local][1] = -987654321;
        xtb[ii][1] = 0;
        for (k = 1; k <= hmm->M; k++) {
            if (mmx[cur_local][k] > -987654321 && hmm->esc[k] > -987654321) {
                sc = mmx[cur_local][k] + hmm->esc[k];
                if (sc > xmx[cur_local][1]) {
                    xmx[cur_local][1] = sc;
                    tb->esrc[ii] = k;
                }
            }
        }
        xmx[cur_local][0] = -987654321;
        xtb[ii][0] = 0;
        if (xmx[cur_local][4] > -987654321 && hmm->xsc[0][0] > -987654321) {
            sc = xmx[cur_local][4] + hmm->xsc[0][0];
            if (sc > xmx[cur_local][0]) {
                xmx[cur_local][0] = sc;
                xtb[ii][0] = 5;
            }
        }
        xmx[cur_local][2] = -987654321;
        xtb[ii][2] = 0;
        if (xmx[prv_local][2] > -987654321 && hmm->xsc[2][1] > -987654321) {
            sc = xmx[prv_local][2] + hmm->xsc[2][1] * mocc[ii];
            if (sc > -987654321) {
                xmx[cur_local][2] = sc;
                xtb[ii][2] = 8;
            }
        }
        if (xmx[cur_local][1] > -987654321 && hmm->xsc[1][0] > -987654321) {
            sc = xmx[cur_local][1] + hmm->xsc[1][0];
            if (sc > xmx[cur_local][2]) {
                xmx[cur_local][2] = sc;
                xtb[ii][2] = 7;
            }
        }
    }
}
}
