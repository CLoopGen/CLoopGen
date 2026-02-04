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
        for (apos = 0; apos < alen; apos++) {
            char current = aseq[i][apos];
            if (current != ' ' && current != '.' && current != '_' && current != '-' && current != '~') {
                continue;
            }
            aseq[i][apos] = gapsym;
        }
    }
}
