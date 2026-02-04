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
    int local_alen = 0;
    for (apos = 0; apos <= M; apos++) {
        int temp_ins = 0;
        for (idx = 0; idx < nseq; idx++) {
            temp_ins = (ins[idx][apos] > temp_ins) ? ins[idx][apos] : temp_ins;
        }
        master_ins[apos] = temp_ins;
        local_alen += temp_ins;
    }
    alen += local_alen;
}
