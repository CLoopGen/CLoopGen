#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_type = type;
    char prev_char = '\0';
    for (temp_type++; ((*temp_type) == ' ' || (*temp_type) == '\t' || (*temp_type) == '\n' || (*temp_type) == '\r' || (*temp_type) == '\f'); temp_type++) {
        prev_char = *(temp_type - 1);
    }
    if (prev_char != '\0') {
        type = temp_type;
    }
}
