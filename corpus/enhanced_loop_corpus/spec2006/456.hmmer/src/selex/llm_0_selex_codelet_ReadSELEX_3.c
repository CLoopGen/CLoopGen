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
extern char *sptr;
extern int seqidx;
extern int count;
extern AINFO *ainfo;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (seqidx = 0; seqidx < num; seqidx++) {
        count = 0;
        char current_char;
        for (int i = 0; (current_char = aseqs[seqidx][i]) != '\x00'; i++) {
            if (!(current_char == ' ' || current_char == '.' || current_char == '_' || 
                  current_char == '-' || current_char == '~')) {
                count++;
            }
        }
        ainfo->sqinfo[seqidx].len = count;
        ainfo->sqinfo[seqidx].flags |= (1 << 6);
    }
}
