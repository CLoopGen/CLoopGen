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
    int stride = 1;
    for (apos = rpos = 0; apos < alen; apos += stride) {
        int unrolled = 0;
        while (unrolled < 4 && apos < alen) {
            if (!((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~')) {
                new[apos] = ss[rpos];
                rpos++;
            } else {
                new[apos] = '.';
            }
            apos++;
            unrolled++;
        }
        apos--; // Compensate for the extra increment in for-loop
    }
}
