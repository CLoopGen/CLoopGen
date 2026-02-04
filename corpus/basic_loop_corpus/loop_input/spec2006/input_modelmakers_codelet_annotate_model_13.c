#include <stdio.h>
#include <stdlib.h>
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

struct plan7_s *hmm;
int *matassign;
MSA *msa;
int apos;
int k;

void init_vars() {
    // Allocate and initialize hmm
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->rf = (char *)malloc(500000);
    for (int i = 0; i < 500000 - 1; i++) {
        hmm->rf[i] = 'X';
    }
    hmm->rf[499999] = '\0';

    // Allocate and initialize msa
    msa = (MSA *)calloc(1, sizeof(MSA));
    msa->alen = 499999;  // Ensure we don't exceed bounds when accessing apos-1
    msa->rf = (char *)malloc(msa->alen + 1);
    for (int i = 0; i < msa->alen; i++) {
        msa->rf[i] = (i % 7 == 0) ? ' ' : ('A' + (i % 25));
    }
    msa->rf[msa->alen] = '\0';

    // Allocate and initialize matassign
    matassign = (int *)calloc(msa->alen + 1, sizeof(int));
    for (int i = 1; i <= msa->alen; i++) {
        matassign[i] = (i % 3 == 0) ? (1 << 0) : 0;
    }
}

// Define extern variables
struct plan7_s *hmm;
int *matassign;
MSA *msa;
int apos;
int k;