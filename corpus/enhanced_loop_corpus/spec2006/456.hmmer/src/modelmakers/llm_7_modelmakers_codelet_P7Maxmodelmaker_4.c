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

extern MSA *msa;
extern int idx;
extern int i;
extern float *sc;
extern int first;
extern int last;
extern float bm1;
extern float bm2;
extern float new;
extern float bestsc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    float *temp_sc = (float*)__builtin_alloca((last + 1) * sizeof(float));
    
    for (i = 1; i <= last; i++) {
        temp_sc[i] = sc[i];
        for (idx = 0; idx < msa->nseq; idx++) {
            if ((msa->aseq[idx][i - 1]) == ' ' || 
                (msa->aseq[idx][i - 1]) == '.' || 
                (msa->aseq[idx][i - 1]) == '_' || 
                (msa->aseq[idx][i - 1]) == '-' || 
                (msa->aseq[idx][i - 1]) == '~')
                temp_sc[i] += bm2;
            else
                temp_sc[i] += bm1;
        }
    }

    bestsc = temp_sc[1];
    first = 1;
    for (i = 2; i <= last; i++) {
        if (temp_sc[i] > bestsc) {
            bestsc = temp_sc[i];
            first = i;
        }
    }
}
