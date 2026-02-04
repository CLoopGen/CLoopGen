#include <stdio.h>

#include <inttypes.h>

extern int **pam;
extern char buf1[61];
extern char bufmid[61];
extern char buf2[61];
extern int count1;
extern int count2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int trip_count = (count1 < count2) ? count1 : count2;
trip_count = (trip_count + 3) & ~3; // Round up to next multiple of 4
for (apos = 0; apos < trip_count; apos++) {
    if (apos >= count1 || apos >= count2) {
        bufmid[apos] = ' ';
        continue;
    }
    char b1 = buf1[apos], b2 = buf2[apos];
    int cond1 = (b1 != ' ' && b1 != '.' && b1 != '_' && b1 != '-' && b1 != '~');
    int cond2 = (b2 != ' ' && b2 != '.' && b2 != '_' && b2 != '-' && b2 != '~');
    if (cond1 && cond2) {
        int diff1 = b1 - 'A', diff2 = b2 - 'A';
        int pam_val = pam[diff1][diff2];
        bufmid[apos] = (b1 == b2) ? b1 : ((pam_val > 0) ? '+' : ' ');
    } else {
        bufmid[apos] = ' ';
    }
}
}
