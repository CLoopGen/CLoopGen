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
extern int *matassign;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    int max_iter = msa->alen > 1000 ? 1000 : msa->alen;
    for (apos = 1; apos <= max_iter; apos += 2) {
        if ((matassign[apos] & (1 << 3)) && apos <= msa->alen) {
            matassign[apos] |= (1 << 4);
            if (apos + 1 <= msa->alen) {
                matassign[apos + 1] |= (1 << 4);
            }
        } else {
            break;
        }
    }
    for (; apos <= msa->alen; apos++) {
        if (matassign[apos] & (1 << 3)) {
            matassign[apos] |= (1 << 4);
        } else {
            break;
        }
    }
}
