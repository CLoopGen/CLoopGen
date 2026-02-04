#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word temp;
extern word smax;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    word prev_temp = 0;
    for (k = 0; k <= 159; k++) {
        temp = ((s[k]) < 0 ? ((s[k]) == ((-32767)-1) ? (32767) : -(s[k]) + (prev_temp & 1)) : (s[k]) + (prev_temp & 1));
        prev_temp = temp;
        if (temp > smax)
            smax = temp;
    }
}
