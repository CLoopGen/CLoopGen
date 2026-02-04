#include <stdio.h>

#include <inttypes.h>

extern char buf1[61];
extern int count1;
extern int rawcount1;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (apos = 0; apos < count1 * 2; apos += 2) {
        i = apos % count1;
        if (!((buf1[i]) == ' ' || (buf1[i]) == '.' || (buf1[i]) == '_' || (buf1[i]) == '-' || (buf1[i]) == '~'))
            rawcount1++;
    }
}
