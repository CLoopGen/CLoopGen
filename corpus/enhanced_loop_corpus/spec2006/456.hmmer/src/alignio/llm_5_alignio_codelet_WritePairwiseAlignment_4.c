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
    for (apos = 0; apos < count1 && apos < count2; apos++) {
        char c1 = buf1[apos];
        char c2 = buf2[apos];
        int is_c1_special = (c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
        int is_c2_special = (c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');

        // Eliminate nested conditionals by flattening control flow with early assignment
        if (is_c1_special || is_c2_special) {
            bufmid[apos] = ' ';
        }
        else if (c1 == c2) {
            bufmid[apos] = c1;
        }
        else if (pam[c1 - 'A'][c2 - 'A'] > 0) {
            bufmid[apos] = '+';
        }
        else {
            bufmid[apos] = ' ';
        }
    }
}
