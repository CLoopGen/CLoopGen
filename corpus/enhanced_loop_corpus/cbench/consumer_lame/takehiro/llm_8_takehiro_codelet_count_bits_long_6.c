#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = i > 576 ? 576 : i;
    for (; limit > 4; limit -= 4) {
        if ((ix[limit - 1] | ix[limit - 2]) & (ix[limit - 3] | ix[limit - 4]))
            break;
    }
    i = limit;
}
