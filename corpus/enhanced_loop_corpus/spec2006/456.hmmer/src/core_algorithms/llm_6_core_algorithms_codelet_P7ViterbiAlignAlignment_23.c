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
    int temp_mmx, temp_dmx, temp_imx;
    for (i = 1; i <= msa->alen; i++) {
        cur = i % 2;
        prv = !cur;
        
        // Initialize current row with sentinel values
        mmx[cur][0] = imx[cur][0] = dmx[cur][0] = -987654321;
        mtb[i][0] = itb[i][0] = dtb[i][0] = 0;

        for (k = 1; k <= hmm->M; k++) {
            // Eliminate WAW dependency by using temporary variables for accumulation
            temp_mmx = -987654321;
            mtb[i][k] = 0;

            if (mmx[prv][k - 1] > -987654321 && hmm->tsc[0][k - 1] > -987654321) {
                sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1];
                if (sc > temp_mmx) {
                    temp_mmx = sc;
                    mtb[i][k] = 1;
                }
            }
            if (imx[prv][k - 1] > -987654321 && hmm->tsc[3][k - 1] > -987654321) {
                sc = imx[prv][k - 1] + hmm->tsc[3][k - 1] * mocc[i - 1];
                if (sc > temp_mmx) {
                    temp_mmx = sc;
                    mtb[i][k] = 3;
                }
            }
            sc = xmx[prv][0] + hmm->bsc[k];
            if (sc > temp_mmx) {
                temp_mmx = sc;
                mtb[i][k] = 6;
            }
            if (dmx[prv][k - 1] > -987654321 && hmm->tsc[5][k - 1] > -987654321) {
                sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1];
                if (sc > temp_mmx) {
                    temp_mmx = sc;
                    mtb[i][k] = 2;
                }
            }

            for (sym = 0; sym < Alphabet_size; sym++) {
                if (con[i][sym] > 0 && hmm->msc[sym][k] == -987654321) {
                    temp_mmx = -987654321;
                    break;
                }
                temp_mmx += hmm->msc[sym][k] * con[i][sym];
            }
            mmx[cur][k] = temp_mmx;

            // D-Matrix update without immediate write-after-write conflict
            temp_dmx = -987654321;
            dtb[i][k] = 0;
            if (mmx[cur][k - 1] > -987654321 && hmm->tsc[2][k - 1] > -987654321) {
                sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1];
                if (sc > temp_dmx) {
                    temp_dmx = sc;
                    dtb[i][k] = 1;
                }
            }
            if (dmx[cur][k - 1] > -987654321 && hmm->tsc[6][k - 1] > -987654321) {
                sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1];
                if (sc > temp_dmx) {
                    temp_dmx = sc;
                    dtb[i][k] = 2;
                }
            }
            dmx[cur][k] = temp_dmx;

            // I-Matrix only computed if not last state
            if (k < hmm->M) {
                temp_imx = -987654321;
                itb[i][k] = 0;
                if (mmx[prv][k] > -987654321 && hmm->tsc[1][k] > -987654321) {
                    sc = mmx[prv][k] + hmm->tsc[1][k] * mocc[i];
                    if (sc > temp_imx) {
                        temp_imx = sc;
                        itb[i][k] = 1;
                    }
                }
                if (imx[prv][k] > -987654321 && hmm->tsc[4][k] > -987654321) {
                    sc = imx[prv][k] + hmm->tsc[4][k] * mocc[i - 1] * mocc[i];
                    if (sc > temp_imx) {
                        temp_imx = sc;
                        itb[i][k] = 3;
                    }
                }
                for (sym = 0; sym < Alphabet_size; sym++) {
                    if (con[i][sym] > 0 && hmm->isc[sym][k] == -987654321) {
                        temp_imx = -987654321;
                        break;
                    }
                    temp_imx += hmm->isc[sym][k] * con[i][sym];
                }
                imx[cur][k] = temp_imx;
            }
        }

        // X-Matrix updates: reduce false dependencies via local temps
        int temp_xmx4 = -987654321;
        xtb[i][4] = 0;
        if (xmx[prv][4] > -987654321 && hmm->xsc[0][1] > -987654321) {
            sc = xmx[prv][4] + hmm->xsc[0][1] * mocc[i];
            if (sc > -987654321) {
                temp_xmx4 = sc;
                xtb[i][4] = 5;
            }
        }
        xmx[cur][4] = temp_xmx4;

        int temp_xmx1 = -987654321;
        xtb[i][1] = 0;
        for (k = 1; k <= hmm->M; k++) {
            if (mmx[cur][k] > -987654321 && hmm->esc[k] > -987654321) {
                sc = mmx[cur][k] + hmm->esc[k];
                if (sc > temp_xmx1) {
                    temp_xmx1 = sc;
                    tb->esrc[i] = k;
                }
            }
        }
        xmx[cur][1] = temp_xmx1;

        int temp_xmx0 = -987654321;
        xtb[i][0] = 0;
        if (xmx[cur][4] > -987654321 && hmm->xsc[0][0] > -987654321) {
            sc = xmx[cur][4] + hmm->xsc[0][0];
            if (sc > temp_xmx0) {
                temp_xmx0 = sc;
                xtb[i][0] = 5;
            }
        }
        xmx[cur][0] = temp_xmx0;

        int temp_xmx2 = -987654321;
        xtb[i][2] = 0;
        if (xmx[prv][2] > -987654321 && hmm->xsc[2][1] > -987654321) {
            sc = xmx[prv][2] + hmm->xsc[2][1] * mocc[i];
            if (sc > -987654321) {
                temp_xmx2 = sc;
                xtb[i][2] = 8;
            }
        }
        if (xmx[cur][1] > -987654321 && hmm->xsc[1][0] > -987654321) {
            sc = xmx[cur][1] + hmm->xsc[1][0];
            if (sc > temp_xmx2) {
                temp_xmx2 = sc;
                xtb[i][2] = 7;
            }
        }
        xmx[cur][2] = temp_xmx2;
    }
}
