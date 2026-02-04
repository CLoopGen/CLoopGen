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
    int apos, rpos;
    char *ss_dst = ainfo->sqinfo[seqidx].ss;
    char *sa_dst = ainfo->sqinfo[seqidx].sa;
    const char *seq_data = aseqs[seqidx];
    int flags = ainfo->sqinfo[seqidx].flags;

    // Introduce combined processing to create WAW dependency on rpos
    // and eliminate redundant checks by caching conditions
    int process_ss = flags & (1 << 9);
    int process_sa = flags & (1 << 10);

    if (process_ss || process_sa) {
        for (apos = rpos = 0; apos < alen; apos++) {
            char c = seq_data[apos];
            int is_gap = (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~');
            if (!is_gap) {
                if (process_ss) {
                    ss_dst[rpos] = ss_dst[apos];  // RAW: ss_dst[apos] read after write in previous iterations (loop-carried)
                }
                if (process_sa) {
                    sa_dst[rpos] = sa_dst[apos];  // RAW dependency on sa_dst
                }
                rpos++;
            }
        }
        if (process_ss) ss_dst[rpos] = '\x00';
        if (process_sa) sa_dst[rpos] = '\x00';
    }
}
}
