#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = type;
    temp_ptr++;
    for (; ((*temp_ptr) == ' ' || (*temp_ptr) == '\t' || (*temp_ptr) == '\n' || (*temp_ptr) == '\r' || (*temp_ptr) == '\f'); temp_ptr++)
        ;
    type = temp_ptr;
}
