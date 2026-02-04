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
char **gcg_aseq;
int idx;
char *s;
int pos;

void init_vars() {
    const int total_data_size = 16 * 1024 * 1024; // ~16MB target data size
    const int avg_seq_len = 512;
    const int nseq_est = total_data_size / avg_seq_len;
    const int nseq = nseq_est > 1000 ? nseq_est : 1000;

    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->nseq = nseq;
    msa->alen = avg_seq_len + 10;
    msa->nseqalloc = nseq;
    
    gcg_aseq = (char**)calloc(nseq, sizeof(char*));
    
    for (int i = 0; i < nseq; i++) {
        gcg_aseq[i] = (char*)malloc((msa->alen + 1) * sizeof(char));
        for (int j = 0; j < msa->alen; j++) {
            int r = rand() % 100;
            if (r < 30)
                gcg_aseq[i][j] = " ._-~"[rand() % 5];
            else
                gcg_aseq[i][j] = 'A' + (rand() % 26);
        }
        gcg_aseq[i][msa->alen] = '\0';
    }

    msa->aseq = (char**)calloc(nseq, sizeof(char*));
    msa->sqname = (char**)calloc(nseq, sizeof(char*));
    msa->wgt = (float*)calloc(nseq, sizeof(float));
    msa->sqlen = (int*)calloc(nseq, sizeof(int));
    msa->sslen = (int*)calloc(nseq, sizeof(int));
    msa->salen = (int*)calloc(nseq, sizeof(int));
    
    for (int i = 0; i < nseq; i++) {
        msa->sqlen[i] = msa->alen;
        msa->wgt[i] = 1.0f;
    }

    msa->gs_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->gc_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->gr_idx = (GKI*)calloc(1, sizeof(GKI));
    msa->index = (GKI*)calloc(1, sizeof(GKI));

    msa->ngs = 0;
    msa->ngc = 0;
    msa->ngr = 0;
    msa->ngf = 0;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;
    msa->alloc_ngf = 0;
    msa->flags = 0;
    msa->type = 0;
    msa->lastidx = -1;

    msa->name = NULL;
    msa->desc = NULL;
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
    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->gr_tag = NULL;
    msa->gr = NULL;

    s = NULL;
    idx = 0;
    pos = 0;
}