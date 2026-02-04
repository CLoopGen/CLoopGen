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
    // Variant 1: Strided memory access (process every 2nd element in a forward pass, then handle remainder)
    for (apos = rpos = 0; apos + 1 < alen; apos += 2) {
        char c1 = aseq[apos];
        char c2 = aseq[apos + 1];
        if (!(c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~')) {
            new[rpos] = ss[apos];
            rpos++;
        }
        if (!(c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~')) {
            new[rpos] = ss[apos + 1];
            rpos++;
        }
    }
    // Handle last element if alen is odd
    if (apos < alen) {
        char c = aseq[apos];
        if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')) {
            new[rpos] = ss[apos];
            rpos++;
        }
    }
}
