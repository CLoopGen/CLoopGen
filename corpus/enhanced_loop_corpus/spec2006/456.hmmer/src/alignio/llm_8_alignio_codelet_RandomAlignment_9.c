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
    int temp1 = 0, temp2 = 0;
    if (apos <= M) {
        for (idx = 0; idx < nseq; idx++) {
            if (ins[idx][apos] > temp1)
                temp1 = ins[idx][apos];
        }
        master_ins[apos] = temp1;
        alen += temp1;
    }
    if (apos + 1 <= M) {
        for (idx = 0; idx < nseq; idx++) {
            if (ins[idx][apos+1] > temp2)
                temp2 = ins[idx][apos+1];
        }
        master_ins[apos+1] = temp2;
        alen += temp2;
    }
}
}
