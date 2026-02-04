#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

MSA *msa;
MSA *new;
int i;

static struct gki_elem **create_gki_table(int size) {
    struct gki_elem **table = malloc(size * sizeof(struct gki_elem *));
    for (int j = 0; j < size; j++) {
        table[j] = NULL;
    }
    return table;
}

static GKI *create_gki() {
    GKI *gki = malloc(sizeof(GKI));
    gki->table = create_gki_table(1024);
    gki->primelevel = 0;
    gki->nhash = 1024;
    gki->nkeys = 0;
    return gki;
}

static char **create_string_array(int count, int len) {
    char **arr = malloc(count * sizeof(char *));
    for (int j = 0; j < count; j++) {
        arr[j] = malloc(len + 1);
        memset(arr[j], 'A' + (j % 26), len);
        arr[j][len] = '\0';
    }
    return arr;
}

static char ***create_3d_string_array(int dim1, int dim2, int len) {
    char ***arr = malloc(dim1 * sizeof(char **));
    for (int i = 0; i < dim1; i++) {
        arr[i] = create_string_array(dim2, len);
    }
    return arr;
}

static float *create_float_array(int count, float val) {
    float *arr = malloc(count * sizeof(float));
    for (int j = 0; j < count; j++) {
        arr[j] = val;
    }
    return arr;
}

static int *create_int_array(int count, int val) {
    int *arr = malloc(count * sizeof(int));
    for (int j = 0; j < count; j++) {
        arr[j] = val;
    }
    return arr;
}

void init_vars() {
    msa = malloc(sizeof(MSA));
    new = malloc(sizeof(MSA));

    msa->alen = 1000;
    msa->nseq = 500;
    msa->flags = 1;
    msa->type = 2;
    msa->name = strdup("original_msa");
    msa->desc = strdup("description");
    msa->acc = strdup("accession");
    msa->au = strdup("author");
    msa->ss_cons = strdup("secondary_structure_consensus");
    msa->sa_cons = strdup("surface_accessibility_consensus");
    msa->rf = strdup("reference_annotation");

    msa->aseq = create_string_array(msa->nseq, msa->alen);
    msa->sqname = create_string_array(msa->nseq, 50);
    msa->wgt = create_float_array(msa->nseq, 1.0f);

    for (int j = 0; j < 6; j++) {
        msa->cutoff[j] = 0.5f + j * 0.1f;
        msa->cutoff_is_set[j] = 1;
    }

    msa->comment = create_string_array(10, 80);
    msa->ncomment = 10;
    msa->alloc_ncomment = 10;

    msa->gf_tag = create_string_array(20, 20);
    msa->gf = create_string_array(20, 100);
    msa->ngf = 20;
    msa->alloc_ngf = 20;

    msa->gs_tag = create_string_array(15, 20);
    msa->gs = create_3d_string_array(15, 5, 30);
    msa->gs_idx = create_gki();
    msa->ngs = 15;

    msa->gc_tag = create_string_array(12, 20);
    msa->gc = create_string_array(12, 100);
    msa->gc_idx = create_gki();
    msa->ngc = 12;

    msa->gr_tag = create_string_array(8, 20);
    msa->gr = create_3d_string_array(8, 4, 25);
    msa->gr_idx = create_gki();
    msa->ngr = 8;

    msa->index = create_gki();
    msa->nseqalloc = 512;
    msa->nseqlump = 1;
    msa->sqlen = create_int_array(msa->nseq, 1000);
    msa->sslen = create_int_array(msa->nseq, 800);
    msa->salen = create_int_array(msa->nseq, 750);
    msa->lastidx = -1;

    new->alen = msa->alen;
    new->nseq = msa->nseq;
    new->flags = msa->flags;
    new->type = msa->type;
    new->name = strdup("new_msa");
    new->desc = strdup("new_description");
    new->acc = strdup("new_accession");
    new->au = strdup("new_author");
    new->ss_cons = strdup("new_ss_cons");
    new->sa_cons = strdup("new_sa_cons");
    new->rf = strdup("new_rf");

    new->aseq = create_string_array(new->nseq, new->alen);
    new->sqname = create_string_array(new->nseq, 50);
    new->wgt = create_float_array(new->nseq, 0.0f);

    for (int j = 0; j < 6; j++) {
        new->cutoff[j] = 0.0f;
        new->cutoff_is_set[j] = 0;
    }

    new->comment = create_string_array(10, 80);
    new->ncomment = 0;
    new->alloc_ncomment = 10;

    new->gf_tag = create_string_array(20, 20);
    new->gf = create_string_array(20, 100);
    new->ngf = 0;
    new->alloc_ngf = 20;

    new->gs_tag = create_string_array(15, 20);
    new->gs = create_3d_string_array(15, 5, 30);
    new->gs_idx = create_gki();
    new->ngs = 0;

    new->gc_tag = create_string_array(12, 20);
    new->gc = create_string_array(12, 100);
    new->gc_idx = create_gki();
    new->ngc = 0;

    new->gr_tag = create_string_array(8, 20);
    new->gr = create_3d_string_array(8, 4, 25);
    new->gr_idx = create_gki();
    new->ngr = 0;

    new->index = create_gki();
    new->nseqalloc = 512;
    new->nseqlump = 1;
    new->sqlen = create_int_array(new->nseq, 0);
    new->sslen = create_int_array(new->nseq, 0);
    new->salen = create_int_array(new->nseq, 0);
    new->lastidx = -1;
}