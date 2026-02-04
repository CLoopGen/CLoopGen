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
for (idx = 0; idx < nseq; idx += 2) {
    for (int offset = 0; offset < 2; ++offset) {
        if (idx + offset >= nseq) continue;
        int cur_idx = idx + offset;
        apos = rpos = 0;
        for (statepos = 0; statepos <= M; statepos++) {
            for (count = 0; count < ins[cur_idx][statepos]; count++)
                aseqs[cur_idx][apos++] = rseqs[cur_idx][rpos++];
            for (; count < master_ins[statepos]; count++)
                aseqs[cur_idx][apos++] = ' ';
            if (statepos != M)
                aseqs[cur_idx][apos++] = rseqs[cur_idx][rpos++];
        }
        aseqs[cur_idx][alen] = '\x00';
    }
}
}
