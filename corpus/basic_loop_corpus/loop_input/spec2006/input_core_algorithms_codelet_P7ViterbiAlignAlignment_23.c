#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int Alphabet_size = 20;
MSA *msa;
struct plan7_s *hmm;
struct dpshadow_s *tb;
int **xmx;
int **mmx;
int **imx;
int **dmx;
char **xtb;
char **mtb;
char **itb;
char **dtb;
float **con;
float *mocc;
int i;
int k;
int sym;
int sc;
int cur;
int prv;

void init_vars() {
    // Allocate and initialize msa
    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->alen = 5000;  // ~200MB data size target
    msa->nseq = 100;
    msa->nseqalloc = 100;
    
    // Allocate mocc
    mocc = (float*)calloc(msa->alen + 1, sizeof(float));
    for (int idx = 0; idx <= msa->alen; idx++) {
        mocc[idx] = 0.1f;
    }

    // Allocate hmm
    hmm = (struct plan7_s*)calloc(1, sizeof(struct plan7_s));
    hmm->M = 400;
    hmm->flags = 1;

    // Allocate arrays in hmm
    hmm->tsc = (int**)calloc(7, sizeof(int*));
    hmm->msc = (int**)calloc(Alphabet_size, sizeof(int*));
    hmm->isc = (int**)calloc(Alphabet_size, sizeof(int*));
    hmm->bsc = (int*)calloc(hmm->M + 1, sizeof(int));
    hmm->esc = (int*)calloc(hmm->M + 1, sizeof(int));
    hmm->map = (int*)calloc(hmm->M + 1, sizeof(int));

    for (int x = 0; x < 7; x++) {
        hmm->tsc[x] = (int*)calloc(hmm->M + 1, sizeof(int));
        for (int y = 0; y <= hmm->M; y++) {
            hmm->tsc[x][y] = -987654321;
        }
    }
    hmm->tsc[0][0] = 0;
    hmm->tsc[1][0] = 0;
    hmm->tsc[2][0] = 0;
    hmm->tsc[3][0] = 0;
    hmm->tsc[4][0] = 0;
    hmm->tsc[5][0] = 0;
    hmm->tsc[6][0] = 0;

    for (int x = 0; x < Alphabet_size; x++) {
        hmm->msc[x] = (int*)calloc(hmm->M + 1, sizeof(int));
        hmm->isc[x] = (int*)calloc(hmm->M + 1, sizeof(int));
        for (int y = 1; y <= hmm->M; y++) {
            hmm->msc[x][y] = -100;
            hmm->isc[x][y] = -100;
        }
    }
    for (int y = 1; y <= hmm->M; y++) {
        hmm->bsc[y] = -100;
        hmm->esc[y] = -100;
        hmm->map[y] = y;
    }

    // Initialize xsc
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 2; b++) {
            hmm->xsc[a][b] = -987654321;
        }
    }
    hmm->xsc[0][0] = -100;
    hmm->xsc[0][1] = -100;
    hmm->xsc[1][0] = -100;
    hmm->xsc[2][1] = -100;

    // Allocate con: [alen+1][Alphabet_size]
    con = (float**)calloc(msa->alen + 1, sizeof(float*));
    for (int idx = 0; idx <= msa->alen; idx++) {
        con[idx] = (float*)calloc(Alphabet_size, sizeof(float));
        for (int s = 0; s < Alphabet_size; s++) {
            con[idx][s] = 1.0f / Alphabet_size;
        }
    }

    // Allocate DP matrices: xmx, mmx, imx, dmx - each [2][max_k+1]
    xmx = (int**)calloc(2, sizeof(int*));
    mmx = (int**)calloc(2, sizeof(int*));
    imx = (int**)calloc(2, sizeof(int*));
    dmx = (int**)calloc(2, sizeof(int*));
    for (int c = 0; c < 2; c++) {
        xmx[c] = (int*)calloc(hmm->M + 5, sizeof(int));
        mmx[c] = (int*)calloc(hmm->M + 1, sizeof(int));
        imx[c] = (int*)calloc(hmm->M + 1, sizeof(int));
        dmx[c] = (int*)calloc(hmm->M + 1, sizeof(int));
        for (int k = 0; k <= hmm->M; k++) {
            mmx[c][k] = -987654321;
            imx[c][k] = -987654321;
            dmx[c][k] = -987654321;
        }
        xmx[c][0] = xmx[c][1] = xmx[c][2] = xmx[c][4] = -987654321;
    }

    // Allocate traceback tables
    tb = (struct dpshadow_s*)calloc(1, sizeof(struct dpshadow_s));
    tb->xtb = (char**)calloc(msa->alen + 1, sizeof(char*));
    tb->mtb = (char**)calloc(msa->alen + 1, sizeof(char*));
    tb->itb = (char**)calloc(msa->alen + 1, sizeof(char*));
    tb->dtb = (char**)calloc(msa->alen + 1, sizeof(char*));
    tb->esrc = (int*)calloc(msa->alen + 1, sizeof(int));

    xtb = tb->xtb;
    mtb = tb->mtb;
    itb = tb->itb;
    dtb = tb->dtb;

    for (int i = 0; i <= msa->alen; i++) {
        xtb[i] = (char*)calloc(5, sizeof(char));
        mtb[i] = (char*)calloc(hmm->M + 1, sizeof(char));
        itb[i] = (char*)calloc(hmm->M + 1, sizeof(char));
        dtb[i] = (char*)calloc(hmm->M + 1, sizeof(char));
    }

    // Initialize boundary conditions
    xmx[0][0] = 0;
}