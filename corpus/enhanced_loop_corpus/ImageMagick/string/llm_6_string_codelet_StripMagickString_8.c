#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = message;
    char prev = '\0';
    for (; *temp != '\x00'; temp++) {
        if (*temp == '\n' && prev != '\r') 
            *temp = ' ';
        prev = *temp;
    }
}
