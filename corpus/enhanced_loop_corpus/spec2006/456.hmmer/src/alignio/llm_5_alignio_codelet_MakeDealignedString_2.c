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
        int is_valid = 1;
        if (c == ' ') is_valid = 0;
        if (c == '.') is_valid = 0;
        if (c == '_') is_valid = 0;
        if (c == '-') is_valid = 0;
        if (c == '~') is_valid = 0;
        if (is_valid) {
            new[rpos] = ss[apos];
            rpos++;
        }
    }
}
