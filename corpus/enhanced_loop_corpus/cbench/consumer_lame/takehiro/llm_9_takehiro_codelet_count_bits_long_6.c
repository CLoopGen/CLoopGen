#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i > 3 && (ix[i - 1] == 0 && ix[i - 2] == 0); i -= 3)
        continue;
    if (i > 1 && ix[i - 1] | ix[i - 2])
        i -= 2;
}
