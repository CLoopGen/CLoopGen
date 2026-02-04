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
    // Variant 1: Strided memory access with stride of 2, unrolled pattern
    // Process two elements per iteration to modify access pattern (strided)
    int i;
    for (apos = rpos = 0; apos + 1 < alen; apos += 2) {
        // Handle current and next element in a strided manner
        char c1 = aseq[apos];
        char c2 = aseq[apos + 1];

        if (!(c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~')) {
            new[apos] = ss[rpos];
            rpos++;
        } else {
            new[apos] = '.';
        }

        if (!(c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~')) {
            new[apos + 1] = ss[rpos];
            rpos++;
        } else {
            new[apos + 1] = '.';
        }
    }
    // Handle remaining element if alen is odd
    if (apos < alen) {
        if (!((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~')) {
            new[apos] = ss[rpos];
            rpos++;
        } else {
            new[apos] = '.';
        }
    }
}
