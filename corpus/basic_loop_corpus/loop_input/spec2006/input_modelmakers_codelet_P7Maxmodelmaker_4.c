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

MSA *msa;
int idx;
int i;
float *sc;
int first;
int last;
float bm1;
float bm2;
float new;
float bestsc;

void init_vars() {
    bm1 = 1.5f;
    bm2 = -0.5f;
    bestsc = -1e30f;

    msa = (MSA *)calloc(1, sizeof(MSA));
    msa->nseq = 1000;
    msa->alen = 100000;
    msa->nseqalloc = msa->nseq;
    last = msa->alen;

    msa->aseq = (char **)calloc(msa->nseq, sizeof(char *));
    for (int j = 0; j < msa->nseq; j++) {
        msa->aseq[j] = (char *)calloc(last + 1, sizeof(char));
        for (int k = 0; k < last; k++) {
            int r = rand() % 20;
            if (r < 2) msa->aseq[j][k] = ' ';
            else if (r < 4) msa->aseq[j][k] = '.';
            else if (r < 6) msa->aseq[j][k] = '_';
            else if (r < 8) msa->aseq[j][k] = '-';
            else if (r < 10) msa->aseq[j][k] = '~';
            else msa->aseq[j][k] = 'A' + (rand() % 20);
        }
        msa->aseq[j][last] = '\0';
    }

    sc = (float *)calloc((last + 1), sizeof(float));
    for (int j = 0; j <= last; j++) {
        sc[j] = (float)(rand() % 1000) / 10.0f;
    }

    first = 1;
}