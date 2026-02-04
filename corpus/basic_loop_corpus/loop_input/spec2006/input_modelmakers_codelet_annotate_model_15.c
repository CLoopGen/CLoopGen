#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    const int data_size = 1 << 20; // ~1MB of input data for ~0.01s runtime

    // Allocate and initialize matassign array (size: alen + 1)
    matassign = calloc(data_size + 1, sizeof(int));
    if (!matassign) exit(1);

    // Initialize msa structure
    msa = malloc(sizeof(MSA));
    if (!msa) exit(1);
    
    memset(msa, 0, sizeof(MSA));
    msa->alen = data_size; // Set alen to control loop iterations
    msa->nseq = 1;

    // Allocate and initialize sa_cons with alternating space and non-space chars
    msa->sa_cons = malloc(data_size);
    if (!msa->sa_cons) exit(1);
    for (int i = 0; i < data_size; i++) {
        msa->sa_cons[i] = (i % 2 == 0) ? 'X' : ' ';
    }

    // Set up HMM structure
    hmm = malloc(sizeof(struct plan7_s));
    if (!hmm) exit(1);
    memset(hmm, 0, sizeof(struct plan7_s));

    // Allocate ca array with sufficient size (k starts at 1 and increments)
    hmm->ca = malloc(data_size);
    if (!hmm->ca) exit(1);
    // Initialize with known value for debugging
    memset(hmm->ca, 0, data_size);

    // Initialize matassign values so that about half the positions trigger the condition
    for (int i = 1; i <= data_size; i++) {
        matassign[i] = (i % 2 == 1) ? (1 << 0) : 0;
    }
}

// Define extern variables at file scope
struct plan7_s *hmm;
int *matassign;
MSA *msa;
int apos;
int k;