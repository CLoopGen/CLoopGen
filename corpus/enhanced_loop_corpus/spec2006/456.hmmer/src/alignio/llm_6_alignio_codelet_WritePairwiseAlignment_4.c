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
    int temp_bufmid[61];
    for (apos = 0; apos < count1 && apos < count2; apos++) {
        temp_bufmid[apos] = ' ';
        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~') && !((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~')) {
            if (buf1[apos] == buf2[apos])
                temp_bufmid[apos] = buf1[apos];
            else if (pam[buf1[apos] - 'A'][buf2[apos] - 'A'] > 0)
                temp_bufmid[apos] = '+';
        }
    }
    for (apos = 0; apos < count1 && apos < count2; apos++) {
        bufmid[apos] = temp_bufmid[apos];
    }
}
