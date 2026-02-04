#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array (simulated using offset indexing)
    char **ptr = &type;
    for (int offset = 0; ((*ptr + offset) == ' ' || (*ptr + offset) == '\t' || (*ptr + offset) == '\n' || (*ptr + offset) == '\r' || (*ptr + offset) == '\f'); offset++)
        ;
}
