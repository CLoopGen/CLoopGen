#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = nextchar;
    for (nameend = temp; *temp && *temp != '='; temp++) {
        nameend = temp + 1;
    }
    if (*temp == '=') {
        nameend = temp;
    }
}
