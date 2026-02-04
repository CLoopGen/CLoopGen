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
int *useme;
int apos;
int idx;

void init_vars() {
    const int target_time_ns = 10000000; // ~10ms target
    const long double base_ops_per_ns = 1.0;
    const int estimated_ops_per_inner_loop = 5;
    
    int alen = (int)((target_time_ns * base_ops_per_ns) / estimated_ops_per_inner_loop);
    if (alen < 1000) alen = 1000;
    if (alen > 256*1024) alen = 256*1024;
    
    int nseq = 200;
    
    msa = (MSA*)calloc(1, sizeof(MSA));
    useme = (int*)calloc(alen, sizeof(int));
    
    msa->alen = alen;
    msa->nseq = nseq;
    msa->nseqalloc = nseq;
    
    msa->aseq = (char**)calloc(nseq, sizeof(char*));
    msa->sqname = (char**)calloc(nseq, sizeof(char*));
    msa->wgt = (float*)calloc(nseq, sizeof(float));
    msa->sqlen = (int*)calloc(nseq, sizeof(int));
    msa->sslen = (int*)calloc(nseq, sizeof(int));
    msa->salen = (int*)calloc(nseq, sizeof(int));
    
    for (int i = 0; i < nseq; i++) {
        msa->aseq[i] = (char*)calloc(alen, sizeof(char));
        msa->sqname[i] = (char*)calloc(32, sizeof(char));
        msa->wgt[i] = 1.0f;
        msa->sqlen[i] = alen;
        msa->sslen[i] = alen;
        msa->salen[i] = alen;
        
        snprintf(msa->sqname[i], 32, "seq_%d", i);
        
        for (int j = 0; j < alen; j++) {
            int r = rand() % 20;
            if (r == 0) msa->aseq[i][j] = ' ';
            else if (r == 1) msa->aseq[i][j] = '.';
            else if (r == 2) msa->aseq[i][j] = '_';
            else if (r == 3) msa->aseq[i][j] = '-';
            else if (r == 4) msa->aseq[i][j] = '~';
            else msa->aseq[i][j] = 'A' + (rand() % 20);
        }
    }
    
    msa->flags = 0;
    msa->type = 0;
    msa->name = strdup("test_msa");
    msa->desc = strdup("synthetic alignment for performance testing");
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;
    
    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;
    
    for (int i = 0; i < 6; i++) {
        msa->cutoff[i] = 0.0f;
        msa->cutoff_is_set[i] = 0;
    }
    
    msa->comment = NULL;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;
    
    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->ngf = 0;
    msa->alloc_ngf = 0;
    
    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->gs_idx = NULL;
    msa->ngs = 0;
    
    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->gc_idx = NULL;
    msa->ngc = 0;
    
    msa->gr_tag = NULL;
    msa->gr = NULL;
    msa->gr_idx = NULL;
    msa->ngr = 0;
    
    msa->index = NULL;
    msa->lastidx = -1;
}