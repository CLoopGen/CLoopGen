#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (STRLEN i = 0; i < len; i++)
        *(s + i) = (((*(s + i)) >= 'A' && (*(s + i)) <= 'Z') ? (*(s + i)) + ('a' - 'A') : (*(s + i)));
}
