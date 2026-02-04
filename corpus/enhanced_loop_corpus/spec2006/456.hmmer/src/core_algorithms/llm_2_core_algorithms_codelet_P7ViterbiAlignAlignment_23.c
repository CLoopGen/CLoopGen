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
    // Variant 1: Consecutive Memory Access Pattern (Row-major order traversal with local accumulation)
    int cur, prv;
    for (int i = 1; i <= msa->alen; i++) {
        cur = i % 2;
        prv = 1 - cur;

        // Initialize current row using consecutive stores
        for (int k = 0; k <= hmm->M; k++) {
            mmx[cur][k] = -987654321;
            imx[cur][k] = -987654321;
            dmx[cur][k] = -987654321;
            mtb[i][k] = 0;
            itb[i][k] = 0;
            dtb[i][k] = 0;
        }

        // Reset boundary condition
        mmx[cur][0] = imx[cur][0] = dmx[cur][0] = -987654321;

        for (int k = 1; k <= hmm->M; k++) {
            int tsc_base = k - 1;
            int *restrict tsc_col = hmm->tsc[0];
            int *restrict msc_row = hmm->msc[0] + k;  // Stride over columns

            // Transition from M state
            if (mmx[prv][k-1] > -987654321 && tsc_col[tsc_base] > -987654321) {
                int sc = mmx[prv][k-1] + tsc_col[tsc_base];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 1;
                }
            }

            // Transition from I state
            if (imx[prv][k-1] > -987654321 && hmm->tsc[3][tsc_base] > -987654321) {
                int sc = imx[prv][k-1] + hmm->tsc[3][tsc_base] * mocc[i-1];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 3;
                }
            }

            // Begin from start state
            if ((xmx[prv][0] + hmm->bsc[k]) > mmx[cur][k]) {
                mmx[cur][k] = xmx[prv][0] + hmm->bsc[k];
                mtb[i][k] = 6;
            }

            // Transition from D state
            if (dmx[prv][k-1] > -987654321 && hmm->tsc[5][tsc_base] > -987654321) {
                int sc = dmx[prv][k-1] + hmm->tsc[5][tsc_base];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 2;
                }
            }

            // Emission scores for M state (accumulate across symbols)
            float sum = 0.0f;
            int invalid = 0;
            for (int sym = 0; sym < Alphabet_size; sym++) {
                if (con[i][sym] > 0 && msc_row[sym * hmm->M] == -987654321) {  // Indirect access pattern
                    invalid = 1;
                    break;
                }
                sum += msc_row[sym * hmm->M] * con[i][sym];
            }
            mmx[cur][k] = invalid ? -987654321 : mmx[cur][k] + sum;

            // D state updates
            dmx[cur][k] = -987654321;
            if (mmx[cur][k-1] > -987654321 && hmm->tsc[2][tsc_base] > -987654321) {
                int sc = mmx[cur][k-1] + hmm->tsc[2][tsc_base];
                if (sc > dmx[cur][k]) {
                    dmx[cur][k] = sc;
                    dtb[i][k] = 1;
                }
            }
            if (dmx[cur][k-1] > -987654321 && hmm->tsc[6][tsc_base] > -987654321) {
                int sc = dmx[cur][k-1] + hmm->tsc[6][tsc_base];
                if (sc > dmx[cur][k]) {
                    dmx[cur][k] = sc;
                    dtb[i][k] = 2;
                }
            }

            // I state update (only for k < M)
            if (k < hmm->M) {
                imx[cur][k] = -987654321;
                if (mmx[prv][k] > -987654321 && hmm->tsc[1][k] > -987654321) {
                    int sc = mmx[prv][k] + hmm->tsc[1][k] * mocc[i];
                    if (sc > imx[cur][k]) {
                        imx[cur][k] = sc;
                        itb[i][k] = 1;
                    }
                }
                if (imx[prv][k] > -987654321 && hmm->tsc[4][k] > -987654321) {
                    int sc = imx[prv][k] + hmm->tsc[4][k] * mocc[i-1] * mocc[i];
                    if (sc > imx[cur][k]) {
                        imx[cur][k] = sc;
                        itb[i][k] = 3;
                    }
                }

                // Emission for I state
                float isum = 0.0f;
                int iinvalid = 0;
                int *isc_ptr = hmm->isc[0] + k;  // Base pointer for isc column
                for (int sym = 0; sym < Alphabet_size; sym++) {
                    if (con[i][sym] > 0 && isc_ptr[sym * hmm->M] == -987654321) {
                        iinvalid = 1;
                        break;
                    }
                    isum += isc_ptr[sym * hmm->M] * con[i][sym];
                }
                imx[cur][k] = iinvalid ? -987654321 : imx[cur][k] + isum;
            }
        }

        // XMX updates using direct indexing
        xmx[cur][4] = -987654321;
        xtb[i][4] = 0;
        if (xmx[prv][4] > -987654321 && hmm->xsc[0][1] > -987654321) {
            int sc = xmx[prv][4] + hmm->xsc[0][1] * mocc[i];
            if (sc > -987654321) {
                xmx[cur][4] = sc;
                xtb[i][4] = 5;
            }
        }

        xmx[cur][1] = -987654321;
        xtb[i][1] = 0;
        tb->esrc[i] = 0;
        for (int k = 1; k <= hmm->M; k++) {
            if (mmx[cur][k] > -987654321 && hmm->esc[k] > -987654321) {
                int sc = mmx[cur][k] + hmm->esc[k];
                if (sc > xmx[cur][1]) {
                    xmx[cur][1] = sc;
                    tb->esrc[i] = k;
                }
            }
        }

        xmx[cur][0] = -987654321;
        xtb[i][0] = 0;
        if (xmx[cur][4] > -987654321 && hmm->xsc[0][0] > -987654321) {
            int sc = xmx[cur][4] + hmm->xsc[0][0];
            if (sc > xmx[cur][0]) {
                xmx[cur][0] = sc;
                xtb[i][0] = 5;
            }
        }

        xmx[cur][2] = -987654321;
        xtb[i][2] = 0;
        if (xmx[prv][2] > -987654321 && hmm->xsc[2][1] > -987654321) {
            int sc = xmx[prv][2] + hmm->xsc[2][1] * mocc[i];
            if (sc > -987654321) {
                xmx[cur][2] = sc;
                xtb[i][2] = 8;
            }
        }
        if (xmx[cur][1] > -987654321 && hmm->xsc[1][0] > -987654321) {
            int sc = xmx[cur][1] + hmm->xsc[1][0];
            if (sc > xmx[cur][2]) {
                xmx[cur][2] = sc;
                xtb[i][2] = 7;
            }
        }
    }
}
