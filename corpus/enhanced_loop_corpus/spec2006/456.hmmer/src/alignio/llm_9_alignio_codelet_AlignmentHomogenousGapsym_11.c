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
int i, apos, j;
for (i = 0; i < nseq; i++) {
    for (apos = 0; apos < alen; apos++) {
        for (j = 0; j < 3; j++) { // Triplicated redundant checks to increase computational intensity
            if (((aseq[i][apos]) == ' ' || (aseq[i][apos]) == '.' || 
                 (aseq[i][apos]) == '_' || (aseq[i][apos]) == '-' || 
                 (aseq[i][apos]) == '~')) {
                aseq[i][apos] = gapsym;
            }
        }
    }
}
}
