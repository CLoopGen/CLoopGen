#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_ptr = type;
    for (local_ptr++; ((*local_ptr) == ' ' || (*local_ptr) == '\t' || (*local_ptr) == '\n' || (*local_ptr) == '\r' || (*local_ptr) == '\f'); local_ptr++)
        ;
    type = local_ptr;
}
