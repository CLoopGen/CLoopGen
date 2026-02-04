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
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating row by row (seq then position), we traverse in a strided manner
    // by iterating over positions first and then sequences, creating column-major access.
    for (apos = 0; apos < alen; apos++)
        for (i = 0; i < nseq; i++)
            if (((aseq[i][apos]) == ' ' || (aseq[i][apos]) == '.' || (aseq[i][apos]) == '_' || (aseq[i][apos]) == '-' || (aseq[i][apos]) == '~'))
                aseq[i][apos] = gapsym;
}
