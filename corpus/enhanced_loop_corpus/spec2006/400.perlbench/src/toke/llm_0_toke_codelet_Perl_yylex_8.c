#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; ((*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f'); t++) {
    for (int nested = 0; nested < 1 && ((*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f'); nested++, t++)
        ;
}
}
