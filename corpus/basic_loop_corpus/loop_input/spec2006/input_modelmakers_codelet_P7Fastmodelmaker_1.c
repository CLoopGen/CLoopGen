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
float maxgap;
int *matassign;
int idx;
int apos;
int ngap;

void init_vars() {
    // Set parameters to achieve ~0.01s runtime
    // Target: alen ~ 1000-5000, nseq ~ 100-200 -> ~100K - 1M comparisons
    // Adjusted empirically for typical CPU speed
    const int alen = 4000;
    const int nseq = 150;

    // Allocate main MSA structure
    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->alen = alen;
    msa->nseq = nseq;
    msa->nseqalloc = nseq;

    // Allocate sequence array
    msa->aseq = (char**)calloc(nseq, sizeof(char*));
    for (int i = 0; i < nseq; i++) {
        msa->aseq[i] = (char*)calloc(alen + 1, sizeof(char));
        // Initialize with random sequence containing gaps
        for (int j = 0; j < alen; j++) {
            float r = (float)rand() / RAND_MAX;
            if (r < 0.25)
                msa->aseq[i][j] = ' ';
            else if (r < 0.5)
                msa->aseq[i][j] = '.';
            else if (r < 0.75)
                msa->aseq[i][j] = '-';
            else
                msa->aseq[i][j] = 'A' + (rand() % 4);
        }
    }

    // Allocate and initialize matassign array (size alen+1)
    matassign = (int*)calloc(alen + 1, sizeof(int));

    // Set maxgap threshold
    maxgap = 0.8f; // 80% gap threshold

    // Initialize other arrays that might be accessed
    msa->sqname = (char**)calloc(nseq, sizeof(char*));
    for (int i = 0; i < nseq; i++) {
        msa->sqname[i] = (char*)calloc(32, sizeof(char));
        sprintf(msa->sqname[i], "seq_%d", i);
    }

    msa->wgt = (float*)calloc(nseq, sizeof(float));
    for (int i = 0; i < nseq; i++)
        msa->wgt[i] = 1.0f;

    msa->sqlen = (int*)calloc(nseq, sizeof(int));
    msa->sslen = (int*)calloc(nseq, sizeof(int));
    msa->salen = (int*)calloc(nseq, sizeof(int));
    for (int i = 0; i < nseq; i++) {
        msa->sqlen[i] = alen;
        msa->sslen[i] = alen;
        msa->salen[i] = alen;
    }

    // Initialize GKI index structures (minimal)
    msa->gs_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->gc_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->gr_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->index = (GKI*)calloc(1, sizeof(GKI));

    // Allocate comment, gf, gs, gc, gr arrays
    msa->ncomment = 0;
    msa->alloc_ncomment = 10;
    msa->comment = (char**)calloc(10, sizeof(char*));

    msa->ngf = 0;
    msa->alloc_ngf = 10;
    msa->gf_tag = (char**)calloc(10, sizeof(char*));
    msa->gf = (char**)calloc(10, sizeof(char*));

    msa->ngs = 0;
    msa->gs_tag = (char**)calloc(10, sizeof(char*));
    msa->gs = (char***)calloc(10, sizeof(char**));

    msa->ngc = 0;
    msa->gc_tag = (char**)calloc(10, sizeof(char*));
    msa->gc = (char**)calloc(10, sizeof(char*));

    msa->ngr = 0;
    msa->gr_tag = (char**)calloc(10, sizeof(char*));
    msa->gr = (char***)calloc(10, sizeof(char**));

    // Initialize strings
    msa->name = strdup("test_msa");
    msa->desc = strdup("benchmark alignment");
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = (char*)calloc(alen + 1, sizeof(char));
    msa->sa_cons = (char*)calloc(alen + 1, sizeof(char));
    msa->rf = (char*)calloc(alen + 1, sizeof(char));
    for (int i = 0; i < alen; i++) {
        msa->ss_cons[i] = 'x';
        msa->sa_cons[i] = 'X';
        msa->rf[i] = '*';
    }

    // Initialize cutoff arrays
    for (int i = 0; i < 6; i++) {
        msa->cutoff[i] = 0.0f;
        msa->cutoff_is_set[i] = 0;
    }

    // Initialize sqacc, sqdesc, ss, sa
    msa->sqacc = (char**)calloc(nseq, sizeof(char*));
    msa->sqdesc = (char**)calloc(nseq, sizeof(char*));
    msa->ss = (char**)calloc(nseq, sizeof(char*));
    msa->sa = (char**)calloc(nseq, sizeof(char*));
    for (int i = 0; i < nseq; i++) {
        msa->sqacc[i] = NULL;
        msa->sqdesc[i] = NULL;
        msa->ss[i] = (char*)calloc(alen + 1, sizeof(char));
        msa->sa[i] = (char*)calloc(alen + 1, sizeof(char));
        memset(msa->ss[i], 'x', alen);
        memset(msa->sa[i], 'X', alen);
    }
}