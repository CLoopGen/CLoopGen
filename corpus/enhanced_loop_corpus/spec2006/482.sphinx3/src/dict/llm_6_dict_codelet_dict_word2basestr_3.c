#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *word;
extern int32 i;
extern int32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_i = len - 2;
    for (i = temp_i; (i > 0) && (word[i] != '('); --i)
        temp_i = i - 1;
}
