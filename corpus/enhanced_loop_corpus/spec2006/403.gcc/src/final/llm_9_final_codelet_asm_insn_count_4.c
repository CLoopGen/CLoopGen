#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *template; template += 2) {
        if (*template == ';' || *template == '\n')
            count++;
        if (*(template + 1) && (*(template + 1) == ';' || *(template + 1) == '\n'))
            count++;
    }
}
