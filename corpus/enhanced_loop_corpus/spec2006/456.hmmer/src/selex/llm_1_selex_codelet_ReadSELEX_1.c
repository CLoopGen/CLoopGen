#include <stdio.h>

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

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;
extern AINFO *ainfo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (seqidx = 0; seqidx < num; seqidx++) {
    int apos, rpos_ss = 0, rpos_sa = 0;
    char process_ss = (ainfo->sqinfo[seqidx].flags & (1 << 9));
    char process_sa = (ainfo->sqinfo[seqidx].flags & (1 << 10));

    if (!(process_ss || process_sa)) continue;

    for (apos = 0; apos < alen; apos++) {
        char ch = aseqs[seqidx][apos];
        int is_gap = (ch == ' ' || ch == '.' || ch == '_' || ch == '-' || ch == '~');

        if (process_ss && !is_gap) {
            ainfo->sqinfo[seqidx].ss[rpos_ss++] = ainfo->sqinfo[seqidx].ss[apos];
        }

        if (process_sa && !is_gap) {
            ainfo->sqinfo[seqidx].sa[rpos_sa++] = ainfo->sqinfo[seqidx].sa[apos];
        }
    }

    if (process_ss) ainfo->sqinfo[seqidx].ss[rpos_ss] = '\x00';
    if (process_sa) ainfo->sqinfo[seqidx].sa[rpos_sa] = '\x00';
}
}
