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
int num = 0;
char *sptr;
int seqidx;
int count;
AINFO *ainfo;

void init_vars() {
    const int num_seqs = 50000;
    num = num_seqs;
    
    aseqs = (char**)calloc(num, sizeof(char*));
    ainfo = (AINFO*)calloc(1, sizeof(AINFO));
    ainfo->sqinfo = (struct seqinfo_s*)calloc(num, sizeof(struct seqinfo_s));
    ainfo->nseq = num;
    
    for (int i = 0; i < num; i++) {
        int len = rand() % 512 + 128;
        aseqs[i] = (char*)malloc((len + 1) * sizeof(char));
        int actual_len = 0;
        for (int j = 0; j < len; j++) {
            char c;
            int r = rand() % 100;
            if (r < 70) {
                c = "ACGT"[rand() % 4];
                actual_len++;
            } else {
                c = " ._-~"[rand() % 5];
            }
            aseqs[i][j] = c;
        }
        aseqs[i][len] = '\x00';
    }
}