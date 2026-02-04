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
    if (useme[apos] == 0)
        continue;
    if (mpos != apos) {
        char **aseq = msa->aseq;
        char **ss = msa->ss;
        char **sa = msa->sa;
        char **gc = msa->gc;
        char *ss_cons = msa->ss_cons;
        char *sa_cons = msa->sa_cons;
        char *rf = msa->rf;
        char ***gr = msa->gr;

        for (idx = 0; idx < msa->nseq; idx++) {
            aseq[idx][mpos] = aseq[idx][apos];
            if (ss != ((void *)0) && ss[idx] != ((void *)0))
                ss[idx][mpos] = ss[idx][apos];
            if (sa != ((void *)0) && sa[idx] != ((void *)0))
                sa[idx][mpos] = sa[idx][apos];
            for (i = 0; i < msa->ngr; i++)
                if (gr[i][idx] != ((void *)0))
                    gr[i][idx][mpos] = gr[i][idx][apos];
        }
        if (ss_cons != ((void *)0))
            ss_cons[mpos] = ss_cons[apos];
        if (sa_cons != ((void *)0))
            sa_cons[mpos] = sa_cons[apos];
        if (rf != ((void *)0))
            rf[mpos] = rf[apos];
        for (i = 0; i < msa->ngc; i++)
            gc[i][mpos] = gc[i][apos];
    }
    mpos++;
}
}
