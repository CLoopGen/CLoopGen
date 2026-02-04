#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = type;
    for (; ((*ptr) == ' ' || (*ptr) == '\t' || (*ptr) == '\n' || (*ptr) == '\r' || (*ptr) == '\f'); ptr++)
        type = ptr + 1;
}
