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
int apos;
int mpos;
int idx;

void init_vars() {
    const int nseq = 100;
    const int seqlen = 2000000; // ~2MB per sequence, total data ~200MB to target 0.01s runtime

    ainfo = (AINFO *)calloc(1, sizeof(AINFO));
    ainfo->nseq = nseq;
    ainfo->alen = seqlen;
    ainfo->wgt = (float *)calloc(nseq, sizeof(float));
    ainfo->cs = (char *)calloc(seqlen, sizeof(char));
    ainfo->rf = (char *)calloc(seqlen, sizeof(char));
    ainfo->sqinfo = (struct seqinfo_s *)calloc(nseq, sizeof(struct seqinfo_s));
    ainfo->name = (char *)calloc(64, sizeof(char));
    ainfo->desc = (char *)calloc(128, sizeof(char));
    ainfo->acc = (char *)calloc(64, sizeof(char));
    ainfo->au = (char *)calloc(64, sizeof(char));

    aseqs = (char **)calloc(nseq, sizeof(char *));
    for (int i = 0; i < nseq; i++) {
        aseqs[i] = (char *)calloc(seqlen + 1, sizeof(char));
        for (int j = 0; j < seqlen; j++) {
            int r = rand() % 20;
            if (r < 16) {
                aseqs[i][j] = "ACGT"[r % 4];
            } else {
                aseqs[i][j] = " ._-~"[r - 16];
            }
        }
        aseqs[i][seqlen] = '\0';
    }

    for (int i = 0; i < seqlen; i++) {
        if (ainfo->cs) ainfo->cs[i] = "ACGT"[i % 4];
        if (ainfo->rf) ainfo->rf[i] = "xyzw"[i % 4];
    }

    apos = 0;
    mpos = 0;
    idx = 0;
}