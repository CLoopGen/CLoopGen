#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int alen;
extern int M;
extern int **ins;
extern int *master_ins;
extern int apos;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (apos = 0; apos <= M; apos += 2) {
    master_ins[apos] = 0;
    if (apos + 1 <= M)
        master_ins[apos + 1] = 0;
    for (idx = 0; idx < nseq; idx++) {
        if (ins[idx][apos] > master_ins[apos])
            master_ins[apos] = ins[idx][apos];
        if (apos + 1 <= M && ins[idx][apos + 1] > master_ins[apos + 1])
            master_ins[apos + 1] = ins[idx][apos + 1];
    }
    alen += master_ins[apos];
    if (apos + 1 <= M)
        alen += master_ins[apos + 1];
}
}
