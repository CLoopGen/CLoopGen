#include <stdio.h>

#include <inttypes.h>

extern char c;
extern  char *p;
extern  char *term_end;
extern  char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_s = p;
    char found = 0;
    for (; !found && local_s < term_end; ++local_s)
        found = (*local_s == c);
    s = local_s - (found ? 1 : 0);
}
