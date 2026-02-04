#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int alen;
extern char *ss;
extern char *new;
extern int apos;
extern int rpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (apos = rpos = 0; apos < alen; apos++) {
        if ((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~') {
            new[apos] = '.';
            continue;
        }
        new[apos] = ss[rpos];
        rpos++;
    }
}
