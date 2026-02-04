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
    // Variant 1: Strided Memory Access (stride of 2, unrolled by factor 2)
    // This variant processes two elements per iteration with a fixed stride pattern to alter memory access behavior.
    int i;
    int limit = (count1 < count2) ? count1 : count2;
    for (i = 0; i < limit; i += 2) {
        apos = i;
        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~') && 
            !((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~')) {
            if (buf1[apos] == buf2[apos])
                bufmid[apos] = buf1[apos];
            else if (pam[buf1[apos] - 'A'][buf2[apos] - 'A'] > 0)
                bufmid[apos] = '+';
            else
                bufmid[apos] = ' ';
        } else
            bufmid[apos] = ' ';

        // Second element in the unrolled iteration
        apos = i + 1;
        if (apos >= count1 || apos >= count2) break;

        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~') && 
            !((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~')) {
            if (buf1[apos] == buf2[apos])
                bufmid[apos] = buf1[apos];
            else if (pam[buf1[apos] - 'A'][buf2[apos] - 'A'] > 0)
                bufmid[apos] = '+';
            else
                bufmid[apos] = ' ';
        } else
            bufmid[apos] = ' ';
    }
}
