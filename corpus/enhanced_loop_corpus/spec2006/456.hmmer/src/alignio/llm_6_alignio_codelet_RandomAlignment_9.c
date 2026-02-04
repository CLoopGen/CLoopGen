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
        int temp_max = 0;
        for (idx = 0; idx < nseq; idx++) {
            if (ins[idx][apos] > temp_max) {
                temp_max = ins[idx][apos];
            }
        }
        master_ins[apos] = temp_max;
        alen += master_ins[apos];
    }
}
