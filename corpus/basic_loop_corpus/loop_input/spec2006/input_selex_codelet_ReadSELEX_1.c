#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct seqinfo_s {
    int flags;
    char name[64];
    char id[64];
    char acc[64];
    char desc[128];
    int len;
    int start;
    int stop;
    int olen;
    int type;
    char *ss;
    char *sa;
};

struct aliinfo_s {
    int flags;
    int alen;
    int nseq;
    float *wgt;
    char *cs;
    char *rf;
    struct seqinfo_s *sqinfo;
    char *name;
    char *desc;
    char *acc;
    char *au;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    float ga1;
    float ga2;
};

typedef struct aliinfo_s AINFO;

#define NUM_SEQS 1000
#define ALIGNED_LEN 100000

char **aseqs;
int num = NUM_SEQS;
int seqidx;
int alen = ALIGNED_LEN;
AINFO *ainfo;

void init_vars() {
    aseqs = (char**)calloc(NUM_SEQS, sizeof(char*));
    ainfo = (AINFO*)calloc(1, sizeof(AINFO));
    ainfo->sqinfo = (struct seqinfo_s*)calloc(NUM_SEQS, sizeof(struct seqinfo_s));
    ainfo->alen = ALIGNED_LEN;
    ainfo->nseq = NUM_SEQS;

    for (int i = 0; i < NUM_SEQS; i++) {
        aseqs[i] = (char*)malloc(ALIGNED_LEN * sizeof(char));
        ainfo->sqinfo[i].ss = (char*)malloc(ALIGNED_LEN * sizeof(char));
        ainfo->sqinfo[i].sa = (char*)malloc(ALIGNED_LEN * sizeof(char));

        if (i % 2 == 0) {
            ainfo->sqinfo[i].flags |= (1 << 9);
        }
        if (i % 3 == 0) {
            ainfo->sqinfo[i].flags |= (1 << 10);
        }

        for (int j = 0; j < ALIGNED_LEN; j++) {
            char base = "ACGT"[j % 4];
            char gap_char = " ._-~ "[j % 5];
            aseqs[i][j] = (j % 7 == 0) ? gap_char : base;
            ainfo->sqinfo[i].ss[j] = base;
            ainfo->sqinfo[i].sa[j] = "ACGU"[j % 4];
        }
    }
}