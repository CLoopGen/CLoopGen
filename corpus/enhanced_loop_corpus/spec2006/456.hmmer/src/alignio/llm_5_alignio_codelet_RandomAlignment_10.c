#include <stdio.h>

#include <inttypes.h>

extern char **rseqs;
extern int nseq;
extern char **aseqs;
extern int alen;
extern int M;
extern int **ins;
extern int *master_ins;
extern int apos;
extern int rpos;
extern int idx;
extern int statepos;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idx = 0; idx < nseq; idx++) {
    apos = rpos = 0;
    for (statepos = 0; statepos <= M; statepos++) {
        int local_count = ins[idx][statepos];
        if (local_count > 0) {
            for (count = 0; count < local_count; count++)
                aseqs[idx][apos++] = rseqs[idx][rpos++];
        } else {
            count = 0;
        }
        for (; count < master_ins[statepos]; count++)
            aseqs[idx][apos++] = ' ';
        if (statepos != M)
            aseqs[idx][apos++] = rseqs[idx][rpos++];
    }
    aseqs[idx][alen] = '\x00';
}
}
