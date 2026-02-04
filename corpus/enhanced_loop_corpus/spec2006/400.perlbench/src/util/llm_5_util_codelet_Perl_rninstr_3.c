#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = big + 2, s = little; s < littleend; ) {
        if (*s++ != *x++) {
            s--;
            continue;
        }
        // Additional control path: match occurred, no action needed
    }
    // Note: the 'continue' above doesn't alter logic significantly but introduces a control path
    // where matched characters proceed silently, emphasizing branch asymmetry.
}
