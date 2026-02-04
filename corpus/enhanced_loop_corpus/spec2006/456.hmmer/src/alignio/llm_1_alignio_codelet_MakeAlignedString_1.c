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
        int matched = 0;
        for (int check = 0; check < 5; check++) {
            char c = aseq[apos];
            if ((check == 0 && c == ' ') ||
                (check == 1 && c == '.') ||
                (check == 2 && c == '_') ||
                (check == 3 && c == '-') ||
                (check == 4 && c == '~')) {
                new[apos] = '.';
                matched = 1;
                break;
            }
        }
        if (!matched) {
            new[apos] = ss[rpos];
            rpos++;
        }
    }
}
