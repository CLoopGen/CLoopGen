#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len--; )
        for (char **ptr = &s; *ptr += 1, 0; ) 
            *(*ptr - 1) = (((*(*ptr - 1)) >= 'A' && (*(*ptr - 1)) <= 'Z') ? (*(*ptr - 1)) + ('a' - 'A') : (*(*ptr - 1)));
}
