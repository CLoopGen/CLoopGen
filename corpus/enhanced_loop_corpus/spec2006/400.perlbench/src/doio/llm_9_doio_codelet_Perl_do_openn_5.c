#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (; ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f') && count < 1000; type++, count++)
    ;
}
