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
        char c = aseq[apos];
        int is_valid = (c != ' ' && c != '.' && c != '_' && c != '-' && c != '~');
        if (!is_valid)
            new[apos] = '.';
        else {
            new[apos] = ss[rpos];
            rpos++;
        }
    }
}
