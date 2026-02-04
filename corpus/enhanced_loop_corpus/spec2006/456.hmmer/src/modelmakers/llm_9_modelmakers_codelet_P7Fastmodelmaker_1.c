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
    int apos, idx;
    int alen = msa->alen;
    int nseq = msa->nseq;
    int *restrict assign = matassign;
    float inv_nseq = 1.0f / nseq;
    float mg = maxgap;

    for (apos = 0; apos < alen; apos += 2) {
        assign[apos + 1] = 0;
        assign[apos + 2] = 0;
        int ngap1 = 0, ngap2 = 0;
        const char *row;
        for (idx = 0; idx < nseq; idx++) {
            row = msa->aseq[idx];
            if (apos < alen) {
                char c1 = row[apos];
                ngap1 += (c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
            }
            if (apos + 1 < alen) {
                char c2 = row[apos + 1];
                ngap2 += (c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');
            }
        }
        if (apos < alen)
            assign[apos + 1] |= (ngap1 * inv_nseq > mg) ? (1 << 3) : (1 << 0);
        if (apos + 1 < alen)
            assign[apos + 2] |= (ngap2 * inv_nseq > mg) ? (1 << 3) : (1 << 0);
    }
}
