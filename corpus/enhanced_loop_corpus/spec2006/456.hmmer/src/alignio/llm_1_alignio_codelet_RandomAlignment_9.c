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
    if (M >= 0) {
        master_ins[0] = 0;
        for (idx = 0; idx < nseq; idx++)
            if (ins[idx][0] > master_ins[0])
                master_ins[0] = ins[idx][0];
        alen += master_ins[0];
    }
    for (apos = 1; apos <= M; apos++) {
        master_ins[apos] = 0;
        for (idx = 0; idx < nseq; idx++)
            if (ins[idx][apos] > master_ins[apos])
                master_ins[apos] = ins[idx][apos];
        alen += master_ins[apos];
    }
}
