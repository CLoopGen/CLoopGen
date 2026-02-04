#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

int nseq;
AINFO *ainfo;
int idx;

void init_vars() {
    nseq = 1000000; 

    ainfo = (AINFO*)calloc(1, sizeof(AINFO));
    if (!ainfo) return;

    ainfo->sqinfo = (struct seqinfo_s*)calloc(nseq, sizeof(struct seqinfo_s));
    if (!ainfo->sqinfo) {
        free(ainfo);
        ainfo = NULL;
        return;
    }

    ainfo->nseq = nseq;
    ainfo->wgt = (float*)calloc(nseq, sizeof(float));
    ainfo->cs = (char*)calloc(nseq, sizeof(char));
    ainfo->rf = (char*)calloc(nseq, sizeof(char));
    ainfo->name = (char*)calloc(64, sizeof(char));
    ainfo->desc = (char*)calloc(128, sizeof(char));
    ainfo->acc = (char*)calloc(64, sizeof(char));
    ainfo->au = (char*)calloc(64, sizeof(char));

    for (int i = 0; i < nseq; i++) {
        struct seqinfo_s* sq = &ainfo->sqinfo[i];
        sq->ss = (char*)calloc(1, sizeof(char));
        sq->sa = (char*)calloc(1, sizeof(char));
        if (sq->ss) sq->ss[0] = '\0';
        if (sq->sa) sq->sa[0] = '\0';
    }

    ainfo->tc1 = 0.0f;
    ainfo->tc2 = 0.0f;
    ainfo->nc1 = 0.0f;
    ainfo->nc2 = 0.0f;
    ainfo->ga1 = 0.0f;
    ainfo->ga2 = 0.0f;
}