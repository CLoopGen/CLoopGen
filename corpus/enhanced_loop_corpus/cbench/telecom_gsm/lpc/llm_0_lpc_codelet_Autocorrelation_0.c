#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word temp;
extern word smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 159; k++) {
        for (int inner = 0; inner < 1; inner++) { // Increased nesting depth with a trivial inner loop
            temp = ((s[k]) < 0 ? ((s[k]) == ((-32767) - 1) ? (32767) : -(s[k])) : (s[k]));
            if (temp > smax)
                smax = temp;
        }
    }
}
