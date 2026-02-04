#include <stdio.h>

#include <inttypes.h>

struct plan7_s {
    char *name;
    char *acc;
    char *desc;
    char *rf;
    char *cs;
    char *ca;
    char *comlog;
    int nseq;
    char *ctime;
    int *map;
    int checksum;
    int *tpri;
    int *mpri;
    int *ipri;
    float ga1;
    float ga2;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    int M;
    float **t;
    float **mat;
    float **ins;
    float tbd1;
    float xt[4][2];
    float *begin;
    float *end;
    float null[20];
    float p1;
    int **tsc;
    int **msc;
    int **isc;
    int xsc[4][2];
    int *bsc;
    int *esc;
    int *tsc_mem;
    int *msc_mem;
    int *isc_mem;
    int *bsc_mem;
    int *esc_mem;
    int **dnam;
    int **dnai;
    int dna2;
    int dna4;
    float mu;
    float lambda;
    int flags;
};


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

extern struct plan7_s *hmm;
extern int *matassign;
extern MSA *msa;
extern int apos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int apos, k;
    // Unroll loop by factor of 4 to increase computational intensity
    int remainder = msa->alen % 4;
    k = 1;

    // Process multiple elements per iteration where possible
    for (apos = 1; apos <= msa->alen - remainder; apos += 4) {
        if (matassign[apos] & (1 << 0)) {
            hmm->ca[k++] = (msa->sa_cons[apos - 1] == ' ') ? '.' : msa->sa_cons[apos - 1];
        }
        if (matassign[apos + 1] & (1 << 0)) {
            hmm->ca[k++] = (msa->sa_cons[apos] == ' ') ? '.' : msa->sa_cons[apos];
        }
        if (matassign[apos + 2] & (1 << 0)) {
            hmm->ca[k++] = (msa->sa_cons[apos + 1] == ' ') ? '.' : msa->sa_cons[apos + 1];
        }
        if (matassign[apos + 3] & (1 << 0)) {
            hmm->ca[k++] = (msa->sa_cons[apos + 2] == ' ') ? '.' : msa->sa_cons[apos + 2];
        }
    }

    // Handle remaining elements
    for (; apos <= msa->alen; apos++) {
        if (matassign[apos] & (1 << 0)) {
            hmm->ca[k++] = (msa->sa_cons[apos - 1] == ' ') ? '.' : msa->sa_cons[apos - 1];
        }
    }
}
