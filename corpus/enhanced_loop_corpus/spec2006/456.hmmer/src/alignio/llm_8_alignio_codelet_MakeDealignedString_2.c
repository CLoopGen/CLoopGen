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
    int i, j;
    for (apos = rpos = 0; apos < alen; apos += 2) {
        for (j = 0; j < 2 && (apos + j) < alen; j++) {
            int idx = apos + j;
            if (!((aseq[idx]) == ' ' || (aseq[idx]) == '.' || (aseq[idx]) == '_' || (aseq[idx]) == '-' || (aseq[idx]) == '~')) {
                new[rpos] = ss[idx];
                rpos++;
            }
        }
    }
}
