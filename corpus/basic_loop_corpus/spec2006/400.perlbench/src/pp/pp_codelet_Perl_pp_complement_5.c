#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; anum >= sizeof(long); anum -= sizeof(long) , tmpl++)
    *tmpl = ~*tmpl;

}
