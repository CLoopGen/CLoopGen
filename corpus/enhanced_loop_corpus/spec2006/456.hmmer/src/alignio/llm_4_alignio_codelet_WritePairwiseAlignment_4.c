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
        // Skip iteration early if either character is in the allowed set
        if ((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~') {
            bufmid[apos] = ' ';
            continue;
        }
        if ((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~') {
            bufmid[apos] = ' ';
            continue;
        }

        // Only process when both characters are not in the allowed set
        if (buf1[apos] == buf2[apos])
            bufmid[apos] = buf1[apos];
        else if (pam[buf1[apos] - 'A'][buf2[apos] - 'A'] > 0)
            bufmid[apos] = '+';
        else
            bufmid[apos] = ' ';
    }
}
