#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; len--; s++)
    *s = (((*s) >= 'A' && (*s) <= 'Z') ? (*s) + ('a' - 'A') : (*s));

}
