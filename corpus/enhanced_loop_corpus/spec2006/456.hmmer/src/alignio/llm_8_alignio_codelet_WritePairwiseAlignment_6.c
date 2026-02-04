#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (apos = 0; apos < count2 * 2; apos += 2) {
        i = apos % count2;
        if (!((buf2[i]) == ' ' || (buf2[i]) == '.' || (buf2[i]) == '_' || (buf2[i]) == '-' || (buf2[i]) == '~'))
            rawcount2++;
    }
}
