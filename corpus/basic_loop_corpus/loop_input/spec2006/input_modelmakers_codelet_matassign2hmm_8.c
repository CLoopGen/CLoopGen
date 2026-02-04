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
int *matassign;
int M = 0;
int apos = 0;

static struct gki_elem **dummy_table = NULL;
static char **dummy_aseq = NULL;
static char **dummy_sqname = NULL;
static float *dummy_wgt = NULL;
static char **dummy_comment = NULL;
static char **dummy_gf_tag = NULL;
static char **dummy_gf = NULL;
static char **dummy_gs_tag = NULL;
static char ***dummy_gs = NULL;
static char **dummy_gc_tag = NULL;
static char **dummy_gc = NULL;
static char **dummy_gr_tag = NULL;
static char ***dummy_gr = NULL;
static int *dummy_sqlen = NULL;
static int *dummy_sslen = NULL;
static int *dummy_salen = NULL;

void init_vars() {
    const int data_size_mb = 128;
    const int approx_elements_per_mb = 1024 * 1024 / sizeof(int);
    const int total_elements = data_size_mb * approx_elements_per_mb;

    matassign = (int*)calloc(total_elements + 2, sizeof(int));
    if (!matassign) exit(1);

    dummy_table = (struct gki_elem**)calloc(1024, sizeof(struct gki_elem*));
    if (!dummy_table) exit(1);

    dummy_aseq = (char**)calloc(1024, sizeof(char*));
    if (!dummy_aseq) exit(1);
    for (int i = 0; i < 1024; i++) {
        dummy_aseq[i] = (char*)calloc(64, sizeof(char));
        if (!dummy_aseq[i]) exit(1);
        strcpy(dummy_aseq[i], "ACGT");
    }

    dummy_sqname = (char**)calloc(1024, sizeof(char*));
    if (!dummy_sqname) exit(1);
    for (int i = 0; i < 1024; i++) {
        dummy_sqname[i] = (char*)calloc(32, sizeof(char));
        if (!dummy_sqname[i]) exit(1);
        sprintf(dummy_sqname[i], "seq_%d", i);
    }

    dummy_wgt = (float*)calloc(1024, sizeof(float));
    if (!dummy_wgt) exit(1);
    for (int i = 0; i < 1024; i++)
        dummy_wgt[i] = 1.0f;

    dummy_comment = (char**)calloc(64, sizeof(char*));
    if (!dummy_comment) exit(1);
    for (int i = 0; i < 64; i++) {
        dummy_comment[i] = (char*)calloc(48, sizeof(char));
        if (!dummy_comment[i]) exit(1);
        sprintf(dummy_comment[i], "comment_%d", i);
    }

    dummy_gf_tag = (char**)calloc(32, sizeof(char*));
    if (!dummy_gf_tag) exit(1);
    dummy_gf = (char**)calloc(32, sizeof(char*));
    if (!dummy_gf) exit(1);
    for (int i = 0; i < 32; i++) {
        dummy_gf_tag[i] = (char*)calloc(16, sizeof(char));
        if (!dummy_gf_tag[i]) exit(1);
        sprintf(dummy_gf_tag[i], "GF%d", i);
        dummy_gf[i] = (char*)calloc(64, sizeof(char));
        if (!dummy_gf[i]) exit(1);
        strcpy(dummy_gf[i], "generic feature value");
    }

    dummy_gs_tag = (char**)calloc(16, sizeof(char*));
    if (!dummy_gs_tag) exit(1);
    dummy_gs = (char***)calloc(16, sizeof(char**));
    if (!dummy_gs) exit(1);
    for (int i = 0; i < 16; i++) {
        dummy_gs_tag[i] = (char*)calloc(16, sizeof(char*));
        if (!dummy_gs_tag[i]) exit(1);
        sprintf(dummy_gs_tag[i], "GS%d", i);
        dummy_gs[i] = (char**)calloc(10, sizeof(char*));
        if (!dummy_gs[i]) exit(1);
        for (int j = 0; j < 10; j++) {
            dummy_gs[i][j] = (char*)calloc(32, sizeof(char));
            if (!dummy_gs[i][j]) exit(1);
            sprintf(dummy_gs[i][j], "gs_value_%d_%d", i, j);
        }
    }

    dummy_gc_tag = (char**)calloc(16, sizeof(char*));
    if (!dummy_gc_tag) exit(1);
    dummy_gc = (char**)calloc(16, sizeof(char*));
    if (!dummy_gc) exit(1);
    for (int i = 0; i < 16; i++) {
        dummy_gc_tag[i] = (char*)calloc(16, sizeof(char));
        if (!dummy_gc_tag[i]) exit(1);
        sprintf(dummy_gc_tag[i], "GC%d", i);
        dummy_gc[i] = (char*)calloc(64, sizeof(char));
        if (!dummy_gc[i]) exit(1);
        strcpy(dummy_gc[i], "conserved feature");
    }

    dummy_gr_tag = (char**)calloc(16, sizeof(char*));
    if (!dummy_gr_tag) exit(1);
    dummy_gr = (char***)calloc(16, sizeof(char**));
    if (!dummy_gr) exit(1);
    for (int i = 0; i < 16; i++) {
        dummy_gr_tag[i] = (char*)calloc(16, sizeof(char));
        if (!dummy_gr_tag[i]) exit(1);
        sprintf(dummy_gr_tag[i], "GR%d", i);
        dummy_gr[i] = (char**)calloc(8, sizeof(char*));
        if (!dummy_gr[i]) exit(1);
        for (int j = 0; j < 8; j++) {
            dummy_gr[i][j] = (char*)calloc(32, sizeof(char));
            if (!dummy_gr[i][j]) exit(1);
            sprintf(dummy_gr[i][j], "region_%d_%d", i, j);
        }
    }

    dummy_sqlen = (int*)calloc(1024, sizeof(int));
    if (!dummy_sqlen) exit(1);
    dummy_sslen = (int*)calloc(1024, sizeof(int));
    if (!dummy_sslen) exit(1);
    dummy_salen = (int*)calloc(1024, sizeof(int));
    if (!dummy_salen) exit(1);
    for (int i = 0; i < 1024; i++) {
        dummy_sqlen[i] = 500;
        dummy_sslen[i] = 500;
        dummy_salen[i] = 500;
    }

    GKI *gs_idx = (GKI*)malloc(sizeof(GKI));
    if (!gs_idx) exit(1);
    gs_idx->table = dummy_table;
    gs_idx->primelevel = 0;
    gs_idx->nhash = 1024;
    gs_idx->nkeys = 0;

    GKI *gc_idx = (GKI*)malloc(sizeof(GKI));
    if (!gc_idx) exit(1);
    gc_idx->table = dummy_table;
    gc_idx->primelevel = 0;
    gc_idx->nhash = 1024;
    gc_idx->nkeys = 0;

    GKI *gr_idx = (GKI*)malloc(sizeof(GKI));
    if (!gr_idx) exit(1);
    gr_idx->table = dummy_table;
    gr_idx->primelevel = 0;
    gr_idx->nhash = 1024;
    gr_idx->nkeys = 0;

    GKI *index = (GKI*)malloc(sizeof(GKI));
    if (!index) exit(1);
    index->table = dummy_table;
    index->primelevel = 0;
    index->nhash = 1024;
    index->nkeys = 0;

    msa = (MSA*)malloc(sizeof(MSA));
    if (!msa) exit(1);

    msa->aseq = dummy_aseq;
    msa->sqname = dummy_sqname;
    msa->wgt = dummy_wgt;
    msa->alen = total_elements;
    msa->nseq = 1024;
    msa->flags = 0;
    msa->type = 0;
    msa->name = NULL;
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;
    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;
    for (int i = 0; i < 6; i++) {
        msa->cutoff[i] = 0.5f;
        msa->cutoff_is_set[i] = 0;
    }
    msa->comment = dummy_comment;
    msa->ncomment = 64;
    msa->alloc_ncomment = 64;
    msa->gf_tag = dummy_gf_tag;
    msa->gf = dummy_gf;
    msa->ngf = 32;
    msa->alloc_ngf = 32;
    msa->gs_tag = dummy_gs_tag;
    msa->gs = dummy_gs;
    msa->gs_idx = gs_idx;
    msa->ngs = 16;
    msa->gc_tag = dummy_gc_tag;
    msa->gc = dummy_gc;
    msa->gc_idx = gc_idx;
    msa->ngc = 16;
    msa->gr_tag = dummy_gr_tag;
    msa->gr = dummy_gr;
    msa->gr_idx = gr_idx;
    msa->ngr = 16;
    msa->index = index;
    msa->nseqalloc = 1024;
    msa->nseqlump = 0;
    msa->sqlen = dummy_sqlen;
    msa->sslen = dummy_sslen;
    msa->salen = dummy_salen;
    msa->lastidx = -1;

    for (int i = 1; i <= msa->alen; i++) {
        matassign[i] = (i % 2 == 0) ? (1 << 0) : 0;
    }
}