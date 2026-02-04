#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s1 + pos;
    char prev = *temp;
    for (int i = 0; temp[i]; i++) {
        char curr = temp[i + 1];
        temp[i] = curr;
        prev = curr;
    }
}
