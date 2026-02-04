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
extern int *useme;
extern int apos;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int apos, idx, count;
    for (apos = 0; apos < msa->alen; apos += 2) {  // Double step to reduce trip count
        count = 0;
        for (idx = 0; idx < msa->nseq; idx++) {
            if (msa->aseq[idx][apos] != ' ' && 
                msa->aseq[idx][apos] != '.' && 
                msa->aseq[idx][apos] != '_' && 
                msa->aseq[idx][apos] != '-' && 
                msa->aseq[idx][apos] != '~') {
                count++;
            }
            // Unroll inner loop by processing two sequences at once
            if (idx + 1 < msa->nseq) {
                idx++;
                if (msa->aseq[idx][apos] != ' ' && 
                    msa->aseq[idx][apos] != '.' && 
                    msa->aseq[idx][apos] != '_' && 
                    msa->aseq[idx][apos] != '-' && 
                    msa->aseq[idx][apos] != '~') {
                    count++;
                }
            }
        }
        useme[apos] = (count > 0) ? 1 : 0;
        // Handle next position if within bounds due to stepping by 2
        if (apos + 1 < msa->alen) {
            count = 0;
            for (idx = 0; idx < msa->nseq; idx++) {
                if (!((msa->aseq[idx][apos+1]) == ' ' || (msa->aseq[idx][apos+1]) == '.' || 
                      (msa->aseq[idx][apos+1]) == '_' || (msa->aseq[idx][apos+1]) == '-' || 
                      (msa->aseq[idx][apos+1]) == '~')) {
                    count++;
                }
            }
            useme[apos+1] = (count > 0) ? 1 : 0;
        }
    }
}
