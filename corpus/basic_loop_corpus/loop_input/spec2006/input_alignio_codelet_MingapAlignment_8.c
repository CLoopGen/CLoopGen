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

char **aseqs;
AINFO *ainfo;
int mpos;
int idx;

void init_vars() {
    const int nseq = 100000;
    const int seq_length = 128;

    ainfo = (AINFO*)malloc(sizeof(AINFO));
    if (!ainfo) exit(1);

    ainfo->nseq = nseq;
    ainfo->alen = seq_length;

    aseqs = (char**)malloc(nseq * sizeof(char*));
    if (!aseqs) exit(1);

    for (int i = 0; i < nseq; i++) {
        aseqs[i] = (char*)malloc(seq_length * sizeof(char));
        if (!aseqs[i]) exit(1);
        memset(aseqs[i], 'A', seq_length - 1);
        aseqs[i][seq_length - 1] = '\0';
    }

    mpos = seq_length - 1;

    ainfo->sqinfo = (struct seqinfo_s*)malloc(nseq * sizeof(struct seqinfo_s));
    if (!ainfo->sqinfo) exit(1);

    for (int i = 0; i < nseq; i++) {
        ainfo->sqinfo[i].flags = 0;
        ainfo->sqinfo[i].len = seq_length;
        ainfo->sqinfo[i].start = 0;
        ainfo->sqinfo[i].stop = seq_length - 1;
        ainfo->sqinfo[i].olen = seq_length;
        ainfo->sqinfo[i].type = 1;
        ainfo->sqinfo[i].ss = NULL;
        ainfo->sqinfo[i].sa = NULL;
        memset(ainfo->sqinfo[i].name, 0, 64);
        memset(ainfo->sqinfo[i].id, 0, 64);
        memset(ainfo->sqinfo[i].acc, 0, 64);
        memset(ainfo->sqinfo[i].desc, 0, 128);
        strcpy(ainfo->sqinfo[i].name, "seq");
        strcat(ainfo->sqinfo[i].name, "i");
    }

    ainfo->wgt = (float*)malloc(nseq * sizeof(float));
    if (!ainfo->wgt) exit(1);
    for (int i = 0; i < nseq; i++)
        ainfo->wgt[i] = 1.0f;

    ainfo->cs = (char*)malloc(seq_length * sizeof(char));
    if (!ainfo->cs) exit(1);
    memset(ainfo->cs, '-', seq_length - 1);
    ainfo->cs[seq_length - 1] = '\0';

    ainfo->rf = (char*)malloc(seq_length * sizeof(char));
    if (!ainfo->rf) exit(1);
    memset(ainfo->rf, '.', seq_length - 1);
    ainfo->rf[seq_length - 1] = '\0';

    ainfo->name = (char*)malloc(1024);
    if (!ainfo->name) exit(1);
    strcpy(ainfo->name, "alignment");

    ainfo->desc = (char*)malloc(1024);
    if (!ainfo->desc) exit(1);
    strcpy(ainfo->desc, "test alignment");

    ainfo->acc = (char*)malloc(1024);
    if (!ainfo->acc) exit(1);
    strcpy(ainfo->acc, "ACC000001");

    ainfo->au = (char*)malloc(1024);
    if (!ainfo->au) exit(1);
    strcpy(ainfo->au, "author");

    ainfo->tc1 = 0.5f;
    ainfo->tc2 = 0.8f;
    ainfo->nc1 = 0.3f;
    ainfo->nc2 = 0.6f;
    ainfo->ga1 = 0.7f;
    ainfo->ga2 = 0.9f;
}