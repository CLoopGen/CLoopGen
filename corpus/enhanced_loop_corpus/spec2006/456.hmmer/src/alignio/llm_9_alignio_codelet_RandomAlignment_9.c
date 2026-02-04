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
    int max_val = -1;
    int count_greater = 0;
    for (idx = 0; idx < nseq; idx++) {
        int val = ins[idx][apos];
        if (val > max_val) {
            max_val = val;
        }
        if (val > 0) {
            count_greater++;
        }
    }
    master_ins[apos] = max_val;
    alen += max_val;
    if (count_greater > nseq / 2) {
        alen++; 
    }
}
}
