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
extern float maxgap;
extern int *matassign;
extern int idx;
extern int apos;
extern int ngap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_matassign = matassign;
    float local_maxgap = maxgap;
    MSA *local_msa = msa;
    for (apos = 0; apos < local_msa->alen; apos++) {
        ngap = 0;
        for (idx = 0; idx < local_msa->nseq; idx++) {
            char c = local_msa->aseq[idx][apos];
            if (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~') {
                ngap++;
            }
        }
        float gap_ratio = (float)ngap / (float)local_msa->nseq;
        local_matassign[apos + 1] = (gap_ratio > local_maxgap) ? (1 << 3) : (1 << 0);
    }
}
