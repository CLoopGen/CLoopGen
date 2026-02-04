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
        int all_gaps = 1;
        for (apos = 0; apos < alen; apos++) {
            if (aseq[i][apos] != ' ' && aseq[i][apos] != '.' && 
                aseq[i][apos] != '_' && aseq[i][apos] != '-' && 
                aseq[i][apos] != '~') {
                all_gaps = 0;
                break;
            }
        }
        if (all_gaps) {
            for (apos = 0; apos < alen; apos++) {
                aseq[i][apos] = gapsym;
            }
        } else {
            for (apos = 0; apos < alen; apos++) {
                if (aseq[i][apos] == ' ' || aseq[i][apos] == '.' || 
                    aseq[i][apos] == '_' || aseq[i][apos] == '-' || 
                    aseq[i][apos] == '~') {
                    aseq[i][apos] = gapsym;
                }
            }
        }
    }
}
