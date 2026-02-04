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
extern int mpos;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (apos = 0, mpos = 0; apos < msa->alen; apos++) {
    if (useme[apos] == 0) {
        continue;
    }
    if (mpos != apos) {
        for (idx = 0; idx < msa->nseq; idx++) {
            char *aseq_src = msa->aseq[idx];
            char *aseq_dst = msa->aseq[idx];
            aseq_dst[mpos] = aseq_src[apos];

            if (msa->ss != ((void *)0)) {
                char *ss_src = msa->ss[idx];
                if (ss_src != ((void *)0)) {
                    ss_src[mpos] = ss_src[apos];
                }
            }
            if (msa->sa != ((void *)0)) {
                char *sa_src = msa->sa[idx];
                if (sa_src != ((void *)0)) {
                    sa_src[mpos] = sa_src[apos];
                }
            }

            for (i = 0; i < msa->ngr; i++) {
                char **gr_row = msa->gr[i];
                if (gr_row[idx] != ((void *)0)) {
                    gr_row[idx][mpos] = gr_row[idx][apos];
                }
            }
        }

        if (msa->ss_cons != ((void *)0)) {
            msa->ss_cons[mpos] = msa->ss_cons[apos];
        }
        if (msa->sa_cons != ((void *)0)) {
            msa->sa_cons[mpos] = msa->sa_cons[apos];
        }
        if (msa->rf != ((void *)0)) {
            msa->rf[mpos] = msa->rf[apos];
        }

        for (i = 0; i < msa->ngc; i++) {
            char *gc_row = msa->gc[i];
            gc_row[mpos] = gc_row[apos];
        }
    }
    mpos++;
}
}
