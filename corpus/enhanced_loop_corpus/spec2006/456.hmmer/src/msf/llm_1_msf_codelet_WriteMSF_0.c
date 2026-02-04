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
extern char **gcg_aseq;
extern int idx;
extern char *s;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idx = 0; idx < msa->nseq; idx++) {
    int front_processed = 0;
    int back_processed = 0;
    for (int phase = 0; phase < 3 && !(front_processed && back_processed); phase++) {
        if (phase == 0) {
            for (s = gcg_aseq[idx]; *s != '\x00' && (*s == ' ' || *s == '.' || *s == '_' || *s == '-' || *s == '~'); s++)
                *s = '~';
            front_processed = 1;
        }
        else if (phase == 1) {
            for (s = gcg_aseq[idx]; *s != '\x00'; s++)
                if (*s == ' ' || *s == '.' || *s == '_' || *s == '-' || *s == '~')
                    *s = '.';
        }
        else if (phase == 2) {
            for (pos = msa->alen - 1; pos > 0 && (gcg_aseq[idx][pos] == ' ' || gcg_aseq[idx][pos] == '.' || 
                                                gcg_aseq[idx][pos] == '_' || gcg_aseq[idx][pos] == '-' || 
                                                gcg_aseq[idx][pos] == '~'); pos--)
                gcg_aseq[idx][pos] = '~';
            back_processed = 1;
        }
    }
}
}
