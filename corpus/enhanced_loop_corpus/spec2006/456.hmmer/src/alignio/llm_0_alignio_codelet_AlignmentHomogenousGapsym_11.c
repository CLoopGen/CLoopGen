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
for (i = 0; i < nseq; i++) {
    apos = 0;
    for (; apos < alen; apos++) {
        char c = aseq[i][apos];
        if (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~') {
            aseq[i][apos] = gapsym;
        }
    }
}
}
