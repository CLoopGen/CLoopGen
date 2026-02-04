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
    char temp_val;
    for (i = 0; i < nseq; i++) {
        for (apos = 0; apos < alen; apos++) {
            temp_val = aseq[i][apos];
            if (temp_val == ' ' || temp_val == '.' || temp_val == '_' || temp_val == '-' || temp_val == '~') {
                aseq[i][apos] = gapsym;
            }
        }
    }
}
