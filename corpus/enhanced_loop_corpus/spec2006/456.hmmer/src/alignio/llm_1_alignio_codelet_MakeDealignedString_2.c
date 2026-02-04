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
        int matched = 0;
        char invalid[] = { ' ', '.', '_', '-', '~' };
        for (int i = 0; i < 5; i++) {
            if (aseq[apos] == invalid[i]) {
                matched = 1;
                break;
            }
        }
        if (!matched) {
            new[rpos] = ss[apos];
            rpos++;
        }
    }
}
