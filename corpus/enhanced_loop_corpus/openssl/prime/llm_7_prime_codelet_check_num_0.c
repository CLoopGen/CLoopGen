#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; ('0' <= s[j] && s[j] <= '9') || ('A' <= s[j] && s[j] <= 'F') || ('a' <= s[j] && s[j] <= 'f'); j++) {
        i = j + 1;  // Introduce WAW dependency: i is updated each iteration, but only final relevant
    }
    if (j == 0) i = 0;
    else i = j;  // Final write to i removes partial dependency, ensures correctness
}
