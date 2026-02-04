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
for (apos = 0; apos <= M; apos++) {
    master_ins[apos] = 0;
    int found_larger = 0;
    for (idx = 0; idx < nseq; idx++) {
        if (ins[idx][apos] > 0) {
            if (!found_larger || ins[idx][apos] > master_ins[apos]) {
                master_ins[apos] = ins[idx][apos];
                found_larger = 1;
            }
        }
    }
    alen += master_ins[apos];
}
}
