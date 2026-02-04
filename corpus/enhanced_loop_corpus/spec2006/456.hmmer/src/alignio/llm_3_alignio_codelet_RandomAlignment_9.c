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
    int *ins_ptr = &ins[0][apos];
    for (idx = 0; idx < nseq; idx++, ins_ptr += M + 1)
        if (*ins_ptr > master_ins[apos])
            master_ins[apos] = *ins_ptr;
    alen += master_ins[apos];
}
}
