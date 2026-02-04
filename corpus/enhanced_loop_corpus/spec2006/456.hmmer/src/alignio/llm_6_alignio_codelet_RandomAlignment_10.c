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



void loop() {
    for (idx = 0; idx < nseq; idx++) {
        apos = rpos = 0;
        int temp_alen = 0;
        for (statepos = 0; statepos <= M; statepos++) {
            int local_ins_count = ins[idx][statepos];
            int master_bound = master_ins[statepos];
            for (count = 0; count < local_ins_count; count++) {
                char c = rseqs[idx][rpos++];
                aseqs[idx][temp_alen++] = c;
            }
            for (; count < master_bound; count++) {
                aseqs[idx][temp_alen++] = ' ';
            }
            if (statepos != M) {
                char rchar = rseqs[idx][rpos++];
                aseqs[idx][temp_alen++] = rchar;
            }
        }
        aseqs[idx][alen] = '\x00';
    }
}
