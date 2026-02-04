#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *e;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (s += 2 , e = s; *e; e++)
    ;

}
