#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0, type++; i < 5 && ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f'); i++, type++)
        ;
}
