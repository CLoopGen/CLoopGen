#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s + 1;
    char current_char;
    for (; (current_char = *temp) && (current_char == ' ' || current_char == '\t' || current_char == '\r'); temp++)
        ;
    t = temp;
}
