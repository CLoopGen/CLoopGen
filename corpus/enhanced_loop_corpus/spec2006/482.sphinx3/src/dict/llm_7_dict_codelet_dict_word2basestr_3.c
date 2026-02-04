#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *word;
extern int32 i;
extern int32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (j = len - 2; (j > 0) && (word[j] != '('); --j)
        i = j; // Introduce WAW dependency on `i`, but write only at end
    if (j >= 0) i = j;
}
