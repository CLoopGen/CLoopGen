#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; anum >= 4 * sizeof(long); anum -= 4 * sizeof(long), tmpl += 4) {
        *tmpl = ~*tmpl;
        *(tmpl + 1) = ~*(tmpl + 1);
        *(tmpl + 2) = ~*(tmpl + 2);
        *(tmpl + 3) = ~*(tmpl + 3);
    }
}
