#include <stdio.h>

#include <inttypes.h>

extern char buf1[61];
extern int count1;
extern int rawcount1;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (apos = 0; apos < count1; apos++) {
        i = 0;
        if ((buf1[apos]) != ' ') i++;
        if ((buf1[apos]) != '.') i++;
        if ((buf1[apos]) != '_') i++;
        if ((buf1[apos]) != '-') i++;
        if ((buf1[apos]) != '~') i++;
        if (i == 5) {
            rawcount1++;
        }
    }
}
