#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rawcount2 = 0;
    for (apos = count2 - 1; apos >= 0; apos--) {
        if (!(buf2[apos] == ' ' || buf2[apos] == '.' || buf2[apos] == '_' || buf2[apos] == '-' || buf2[apos] == '~')) {
            rawcount2 = rawcount2 + 1;
        }
    }
}
