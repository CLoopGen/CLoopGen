#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; ('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F') || ('a' <= s[i] && s[i] <= 'f'); i++) {
        // Increase computational intensity by adding redundant but safe arithmetic operations
        j = i + 1;
        j = j * 2 - 1;
        j = (j >> 1) + i;
        (void)j; // Prevent unused variable warning
    }
}
