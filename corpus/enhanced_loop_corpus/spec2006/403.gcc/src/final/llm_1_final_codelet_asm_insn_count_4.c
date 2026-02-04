#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *template && !((*template) == ';' || *template == '\n'); template++)
        ; // Outer loop advances until a delimiter is found

    if (*template) // Process the delimiter once outside the main scanning loop
        count++;
}
