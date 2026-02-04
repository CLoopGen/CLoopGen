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
        int write_offset = 0;
        int read_offset = 0;
        for (statepos = 0; statepos <= M; statepos++) {
            int current_ins = ins[idx][statepos];
            int shared_limit = master_ins[statepos];
            for (count = 0; count < current_ins; count++) {
                aseqs[idx][write_offset] = rseqs[idx][read_offset];
                write_offset++;
                read_offset++;
            }
            while (count < shared_limit) {
                aseqs[idx][write_offset] = ' ';
                write_offset++;
                count++;
            }
            if (statepos != M) {
                aseqs[idx][write_offset] = rseqs[idx][read_offset];
                write_offset++;
                read_offset++;
            }
        }
        aseqs[idx][alen] = '\x00';
    }
}
