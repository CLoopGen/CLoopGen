#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    const int data_size = 131072; // ~1MB of input data for matassign, ensures loop runtime ~0.01s

    // Initialize msa
    msa = (MSA *)calloc(1, sizeof(MSA));
    msa->alen = data_size;
    msa->nseq = 100;
    msa->nseqalloc = 100;

    // Allocate and initialize matassign with sufficient size
    matassign = (int *)calloc(data_size + 1, sizeof(int));
    for (int i = 1; i <= data_size; i++) {
        matassign[i] = (i % 3 == 0) ? (1 << 0) : 0; // every third position triggers the condition
    }

    // Allocate hmm
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = data_size / 4; // reasonable model size
    hmm->map = (int *)malloc((data_size + 1) * sizeof(int)); // k goes up to at most data_size
}