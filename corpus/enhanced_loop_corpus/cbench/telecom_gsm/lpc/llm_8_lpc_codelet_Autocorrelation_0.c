#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word temp;
extern word smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 79; k += 2) {
        temp = ((s[k]) < 0 ? ((s[k]) == ((-32767) - 1) ? (32767) : -(s[k])) : (s[k]));
        if (temp > smax)
            smax = temp;
        temp = ((s[k+1]) < 0 ? ((s[k+1]) == ((-32767) - 1) ? (32767) : -(s[k+1])) : (s[k+1]));
        if (temp > smax)
            smax = temp;
    }
}
