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
extern int mpos;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies and make iterations fully independent
    // Unroll the loop by groups of 4 for better ILP, assuming nseq is multiple of 4 (or handle remainder-safe)
    int end = msa->nseq;
    int remainder = end % 4;

    // Process main unrolled part: no loop-carried deps, all writes are independent
    for (idx = 0; idx < end - remainder; idx += 4) {
        // Process 4 elements in parallel (independent)
        msa->aseq[idx + 0][mpos] = '\x00';
        msa->aseq[idx + 1][mpos] = '\x00';
        msa->aseq[idx + 2][mpos] = '\x00';
        msa->aseq[idx + 3][mpos] = '\x00';

        if (msa->ss != ((void *)0)) {
            if (msa->ss[idx + 0] != ((void *)0)) msa->ss[idx + 0][mpos] = '\x00';
            if (msa->ss[idx + 1] != ((void *)0)) msa->ss[idx + 1][mpos] = '\x00';
            if (msa->ss[idx + 2] != ((void *)0)) msa->ss[idx + 2][mpos] = '\x00';
            if (msa->ss[idx + 3] != ((void *)0)) msa->ss[idx + 3][mpos] = '\x00';
        }

        if (msa->sa != ((void *)0)) {
            if (msa->sa[idx + 0] != ((void *)0)) msa->sa[idx + 0][mpos] = '\x00';
            if (msa->sa[idx + 1] != ((void *)0)) msa->sa[idx + 1][mpos] = '\x00';
            if (msa->sa[idx + 2] != ((void *)0)) msa->sa[idx + 2][mpos] = '\x00';
            if (msa->sa[idx + 3] != ((void *)0)) msa->sa[idx + 3][mpos] = '\x00';
        }

        // Fully unroll gr updates for fixed small msa->ngr (assume compile-time bound or limit)
        for (i = 0; i < msa->ngr; i++) {
            if (msa->gr[i][idx + 0] != ((void *)0)) msa->gr[i][idx + 0][mpos] = '\x00';
            if (msa->gr[i][idx + 1] != ((void *)0)) msa->gr[i][idx + 1][mpos] = '\x00';
            if (msa->gr[i][idx + 2] != ((void *)0)) msa->gr[i][idx + 2][mpos] = '\x00';
            if (msa->gr[i][idx + 3] != ((void *)0)) msa->gr[i][idx + 3][mpos] = '\x00';
        }
    }

    // Handle leftover iterations without introducing dependencies
    for (; idx < end; idx++) {
        msa->aseq[idx][mpos] = '\x00';
        if (msa->ss != ((void *)0) && msa->ss[idx] != ((void *)0))
            msa->ss[idx][mpos] = '\x00';
        if (msa->sa != ((void *)0) && msa->sa[idx] != ((void *)0))
            msa->sa[idx][mpos] = '\x00';
        for (i = 0; i < msa->ngr; i++)
            if (msa->gr[i][idx] != ((void *)0))
                msa->gr[i][idx][mpos] = '\x00';
    }
}
