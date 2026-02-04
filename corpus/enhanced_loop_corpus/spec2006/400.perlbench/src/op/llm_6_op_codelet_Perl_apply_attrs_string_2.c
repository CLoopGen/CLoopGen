#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char current_char;
    STRLEN local_len = len;
    for (; local_len; --local_len) {
        current_char = *attrstr;
        if (current_char == ' ' || current_char == '\t' || current_char == '\n' || current_char == '\r' || current_char == '\f') 
            break;
        ++attrstr;
    }
    len = local_len;
}
