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
    int local_rpos = 0;
    for (apos = 0; apos < alen; apos++) {
        char c = aseq[apos];
        if (c != ' ' && c != '.' && c != '_' && c != '-' && c != '~') {
            new[local_rpos] = ss[apos];
            local_rpos++;
        }
    }
    rpos = local_rpos;
}
