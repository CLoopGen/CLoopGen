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
    for (apos = 0; apos < alen; apos++) {
        rpos = 0;
        if (!((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~')) {
            for (int nested = 0; nested < 1; nested++) {
                new[rpos] = ss[apos];
                rpos++;
            }
        }
    }
}
