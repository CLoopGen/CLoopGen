#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *peek;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s;
    while ((*temp) == ' ' || (*temp) == '\t') {
        temp++;
    }
    peek = temp;
}
