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
    // Introduce loop-carried dependence via cumulative score propagation
    int carry_score = 0;
    for (i = 1; i <= msa->alen; i++) {
        cur = i % 2;
        prv = !cur;

        // Introduce artificial RAW dependency from previous iteration
        mmx[cur][0] = imx[cur][0] = dmx[cur][0] = -987654321 + carry_score;
        mtb[i][0] = itb[i][0] = dtb[i][0] = 0;

        for (k = 1; k <= hmm->M; k++) {
            mmx[cur][k] = -987654321 + carry_score;
            mtb[i][k] = 0;

            // Add dependence on prior k via chained comparison
            int prev_k_valid = (k > 1) && (mmx[prv][k - 1] > -987654321);
            if (prev_k_valid && hmm->tsc[0][k - 1] > -987654321) {
                sc = mmx[prv][k - 1] + hmm->tsc[0][k - 1];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 1;
                }
            }

            if (imx[prv][k - 1] > -987654321 && hmm->tsc[3][k - 1] > -987654321) {
                sc = imx[prv][k - 1] + hmm->tsc[3][k - 1] * mocc[i - 1];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 3;
                }
            }

            sc = xmx[prv][0] + hmm->bsc[k];
            if (sc > mmx[cur][k]) {
                mmx[cur][k] = sc;
                mtb[i][k] = 6;
            }

            if (dmx[prv][k - 1] > -987654321 && hmm->tsc[5][k - 1] > -987654321) {
                sc = dmx[prv][k - 1] + hmm->tsc[5][k - 1];
                if (sc > mmx[cur][k]) {
                    mmx[cur][k] = sc;
                    mtb[i][k] = 2;
                }
            }

            // Introduce WAR hazard by reusing `sym` after inner loop
            int total_weight = 0;
            for (sym = 0; sym < Alphabet_size; sym++) {
                if (con[i][sym] > 0 && hmm->msc[sym][k] == -987654321) {
                    mmx[cur][k] = -987654321;
                    break;
                }
                mmx[cur][k] += hmm->msc[sym][k] * con[i][sym];
                total_weight += con[i][sym];
            }

            // Use `sym` post-loop creates WAR anti-dependence
            if (sym == Alphabet_size && total_weight > 0.5f) {
                mmx[cur][k] += carry_score;
            }

            dmx[cur][k] = -987654321;
            dtb[i][k] = 0;
            if (mmx[cur][k - 1] > -987654321 && hmm->tsc[2][k - 1] > -987654321) {
                sc = mmx[cur][k - 1] + hmm->tsc[2][k - 1];
                if (sc > dmx[cur][k]) {
                    dmx[cur][k] = sc;
                    dtb[i][k] = 1;
                }
            }
            if (dmx[cur][k - 1] > -987654321 && hmm->tsc[6][k - 1] > -987654321) {
                sc = dmx[cur][k - 1] + hmm->tsc[6][k - 1];
                if (sc > dmx[cur][k]) {
                    dmx[cur][k] = sc;
                    dtb[i][k] = 2;
                }
            }

            if (k < hmm->M) {
                imx[cur][k] = -987654321;
                itb[i][k] = 0;
                if (mmx[prv][k] > -987654321 && hmm->tsc[1][k] > -987654321) {
                    sc = mmx[prv][k] + hmm->tsc[1][k] * mocc[i];
                    if (sc > imx[cur][k]) {
                        imx[cur][k] = sc;
                        itb[i][k] = 1;
                    }
                }
                if (imx[prv][k] > -987654321 && hmm->tsc[4][k] > -987654321) {
                    sc = imx[prv][k] + hmm->tsc[4][k] * mocc[i - 1] * mocc[i];
                    if (sc > imx[cur][k]) {
                        imx[cur][k] = sc;
                        itb[i][k] = 3;
                    }
                }
                for (sym = 0; sym < Alphabet_size; sym++) {
                    if (con[i][sym] > 0 && hmm->isc[sym][k] == -987654321) {
                        imx[cur][k] = -987654321;
                        break;
                    }
                    imx[cur][k] += hmm->isc[sym][k] * con[i][sym];
                }
            }
        }

        // Update carry score to create loop-carried dependency
        carry_score = (xmx[prv][4] > -987654321) ? (xmx[prv][4] % 1000) : 0;

        xmx[cur][4] = -987654321;
        xtb[i][4] = 0;
        if (xmx[prv][4] > -987654321 && hmm->xsc[0][1] > -987654321) {
            sc = xmx[prv][4] + hmm->xsc[0][1] * mocc[i] + carry_score;
            if (sc > -987654321) {
                xmx[cur][4] = sc;
                xtb[i][4] = 5;
            }
        }

        xmx[cur][1] = -987654321;
        xtb[i][1] = 0;
        for (k = 1; k <= hmm->M; k++) {
            if (mmx[cur][k] > -987654321 && hmm->esc[k] > -987654321) {
                sc = mmx[cur][k] + hmm->esc[k];
                if (sc > xmx[cur][1]) {
                    xmx[cur][1] = sc;
                    tb->esrc[i] = k;
                }
            }
        }

        xmx[cur][0] = -987654321;
        xtb[i][0] = 0;
        if (xmx[cur][4] > -987654321 && hmm->xsc[0][0] > -987654321) {
            sc = xmx[cur][4] + hmm->xsc[0][0];
            if (sc > xmx[cur][0]) {
                xmx[cur][0] = sc;
                xtb[i][0] = 5;
            }
        }

        xmx[cur][2] = -987654321;
        xtb[i][2] = 0;
        if (xmx[prv][2] > -987654321 && hmm->xsc[2][1] > -987654321) {
            sc = xmx[prv][2] + hmm->xsc[2][1] * mocc[i] + carry_score;
            if (sc > -987654321) {
                xmx[cur][2] = sc;
                xtb[i][2] = 8;
            }
        }
        if (xmx[cur][1] > -987654321 && hmm->xsc[1][0] > -987654321) {
            sc = xmx[cur][1] + hmm->xsc[1][0];
            if (sc > xmx[cur][2]) {
                xmx[cur][2] = sc;
                xtb[i][2] = 7;
            }
        }
    }
}
