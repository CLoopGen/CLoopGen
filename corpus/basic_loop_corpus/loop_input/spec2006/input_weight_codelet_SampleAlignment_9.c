#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

MSA *msa;
int *list;
int *useme;
int i;

void init_vars() {
    const int target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const long long cpu_speed_guess = 3000000000LL; // 3 GHz
    const int ops_per_iter = 2; // Two stores per iteration
    int nseq = (target_time_ns * cpu_speed_guess) / (1e9 * ops_per_iter);
    if (nseq < 1000) nseq = 1000;
    if (nseq > 256 * 1024 * 1024) nseq = 256 * 1024 * 1024;

    msa = (MSA *)calloc(1, sizeof(MSA));
    msa->nseq = nseq;
    msa->nseqalloc = nseq;

    list = (int *)malloc(nseq * sizeof(int));
    useme = (int *)malloc(nseq * sizeof(int));

    for (int j = 0; j < nseq; j++) {
        list[j] = -1;
        useme[j] = -1;
    }
}