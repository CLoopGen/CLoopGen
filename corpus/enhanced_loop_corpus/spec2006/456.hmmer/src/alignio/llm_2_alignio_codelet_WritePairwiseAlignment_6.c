#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < count2; i += 2) {
        if (i < count2 && !((buf2[i]) == ' ' || (buf2[i]) == '.' || (buf2[i]) == '_' || (buf2[i]) == '-' || (buf2[i]) == '~'))
            rawcount2++;
        if (i + 1 < count2 && !((buf2[i+1]) == ' ' || (buf2[i+1]) == '.' || (buf2[i+1]) == '_' || (buf2[i+1]) == '-' || (buf2[i+1]) == '~'))
            rawcount2++;
    }
}
