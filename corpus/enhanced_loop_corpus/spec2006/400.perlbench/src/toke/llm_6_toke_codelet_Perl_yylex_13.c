#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char current_char;
    STRLEN temp_len = len;
    for (; temp_len; --temp_len) {
        current_char = *d;
        if (current_char == ' ' || current_char == '\t' || current_char == '\n' || current_char == '\r' || current_char == '\f') break;
        ++d;
    }
    len = temp_len;
}
