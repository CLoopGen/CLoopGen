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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing ins[idx][statepos] directly, use a stride-based access via pointer arithmetic
    // to simulate a strided pattern over the ins matrix. Also reorganize inner loop order for stride clarity.

    int *ins_row;
    char *rseq, *aseq;
    int total_ins_count, master_count;

    for (idx = 0; idx < nseq; idx++) {
        apos = rpos = 0;
        rseq = rseqs[idx];
        aseq = aseqs[idx];
        ins_row = ins[idx];

        for (statepos = 0; statepos <= M; statepos++) {
            total_ins_count = ins_row[statepos];
            master_count = master_ins[statepos];

            // First, insert characters from rseq with strided write pattern (every 2nd position)
            for (count = 0; count < total_ins_count; count++) {
                aseq[apos] = rseq[rpos];
                apos += 2;  // Strided write: write every other position
                rpos++;
            }
            apos -= total_ins_count;  // rewind readjustment for fill

            // Fill intermediate strided positions with space
            for (int j = 0; j < total_ins_count; j++) {
                if (apos % 2 != 0) apos++;  // ensure alignment if needed
                aseq[apos + 1] = ' ';
            }
            apos += 2 * total_ins_count;

            // Then fill remaining stride positions up to master_ins with spaces
            int remaining = master_count - total_ins_count;
            for (count = 0; count < remaining; count++) {
                aseq[apos] = ' ';
                apos += 2;
            }

            // Place match character (if not last state) in contiguous location
            if (statepos != M) {
                aseq[apos++] = rseq[rpos++];
            }
        }
        aseq[alen] = '\x00';
    }
}
