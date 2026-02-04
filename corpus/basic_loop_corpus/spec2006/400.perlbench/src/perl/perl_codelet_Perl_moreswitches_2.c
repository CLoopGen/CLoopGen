#include <stdio.h>

#include <inttypes.h>

extern char *PL_inplace;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (s = PL_inplace; *s && !((*s) == ' ' || (*s) == '\t' || (*s) == '\n' || (*s) == '\r' || (*s) == '\f'); s++)
    ;

}
