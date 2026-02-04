#include <stdio.h>

#include <inttypes.h>

extern char **aseq;
extern int nseq;
extern int alen;
extern char gapsym;
extern int i;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nseq <= 0 || alen <= 0) return;
for (i = 0; i < nseq * alen; i++) {
    int seq_idx = i / alen;
    int pos_idx = i % alen;
    char c = aseq[seq_idx][pos_idx];
    if (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~') {
        aseq[seq_idx][pos_idx] = gapsym;
    }
}
}
