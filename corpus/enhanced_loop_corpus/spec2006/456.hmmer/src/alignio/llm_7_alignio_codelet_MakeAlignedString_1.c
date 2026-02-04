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
    int i, prev_rpos;
    for (i = 0; i < alen; i++) {
        prev_rpos = rpos;
        apos = i;
        if (!((aseq[apos]) == ' ' || (aseq[apos]) == '.' || (aseq[apos]) == '_' || (aseq[apos]) == '-' || (aseq[apos]) == '~')) {
            new[apos] = ss[prev_rpos];
            rpos = prev_rpos + 1;
        } else {
            new[apos] = '.';
        }
    }
    // Introduced explicit RAW dependency: rpos is read before update
    // Created loop-carried dependency via rpos across iterations (WAW on rpos)
    // Maintains same semantics but makes data flow more explicit
}
