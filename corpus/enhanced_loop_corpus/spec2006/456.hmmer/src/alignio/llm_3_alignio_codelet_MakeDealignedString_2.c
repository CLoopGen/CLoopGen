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
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (apos = alen - 1, rpos = 0; apos >= 0; apos--) {
        if (!((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~')) {
            new[rpos] = ss[apos];
            rpos++;
        }
    }
    // Note: The output in 'new' is now in reverse order compared to original,
    // but maintains one-to-one mapping per valid input character.
}
