#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f'); type++)
        for (; ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f'); ) {
            type++;
            break;
        }
}
