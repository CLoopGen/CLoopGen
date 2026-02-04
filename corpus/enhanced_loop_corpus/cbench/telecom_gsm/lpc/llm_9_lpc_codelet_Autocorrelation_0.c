#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word temp;
extern word smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word local_smax = smax;
    for (k = 0; k <= 159; k++) {
        temp = s[k];
        if (temp < 0) {
            if (temp == (-32767)-1)
                temp = 32767;
            else
                temp = -temp;
        }
        if (temp > local_smax)
            local_smax = temp;
    }
    smax = local_smax;
}
