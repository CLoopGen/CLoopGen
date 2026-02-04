#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *word;
extern int32 i;
extern int32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len - 2; (i > 0) && (word[i] != '(') && (word[i-1] != ')'); --i)
        ;
}
