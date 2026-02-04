#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j)
        for (; i > 1; i -= 2)
            if (ix[i - 1] | ix[i - 2])
                break;
}
