#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; (*type) != '\0'; type++) {
        if ((*type) != ' ' && (*type) != '\t' && (*type) != '\n' && (*type) != '\r' && (*type) != '\f') {
            break;
        }
    }
}
