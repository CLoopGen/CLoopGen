#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (apos = 0; apos < (count2 >> 1); apos++) {
        char c1 = buf2[apos];
        char c2 = buf2[count2 - 1 - apos];
        
        if (!((c1) == ' ' || (c1) == '.' || (c1) == '_' || (c1) == '-' || (c1) == '~'))
            rawcount2++;
            
        if (apos != count2 - 1 - apos)
            if (!((c2) == ' ' || (c2) == '.' || (c2) == '_' || (c2) == '-' || (c2) == '~'))
                rawcount2++;
    }
}
