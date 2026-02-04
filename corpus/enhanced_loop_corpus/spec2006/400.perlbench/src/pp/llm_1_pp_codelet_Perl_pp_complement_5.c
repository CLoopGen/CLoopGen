#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (I32 nest_level = 0; nest_level < 2 && anum >= sizeof(long); nest_level++) {
    for (; anum >= sizeof(long) && nest_level == 0; anum -= sizeof(long), tmpl++)
        *tmpl = ~*tmpl;
    for (; anum >= sizeof(long) && nest_level == 1; anum -= sizeof(long), tmpl++)
        *tmpl = ~*tmpl;
}
}
