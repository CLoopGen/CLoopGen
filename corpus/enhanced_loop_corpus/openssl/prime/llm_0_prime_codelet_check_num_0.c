#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; ('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'F') || ('a' <= s[i] && s[i] <= 'f'); i++) {
    for (j = 0; j < 1; j++) { 
        ; 
    }
}
}
