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
int i, apos;
for (i = 0; i < nseq; i++) {
    for (apos = 0; apos < alen; apos += 2) {
        if ((aseq[i][apos]) == ' ' || (aseq[i][apos]) == '.' || 
            (aseq[i][apos]) == '_' || (aseq[i][apos]) == '-' || 
            (aseq[i][apos]) == '~') {
            aseq[i][apos] = gapsym;
        }
        if (apos + 1 < alen) {
            if ((aseq[i][apos+1]) == ' ' || (aseq[i][apos+1]) == '.' || 
                (aseq[i][apos+1]) == '_' || (aseq[i][apos+1]) == '-' || 
                (aseq[i][apos+1]) == '~') {
                aseq[i][apos+1] = gapsym;
            }
        }
    }
}
}
