#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f'); ) {
        if ((*type) == ' ') {
            type++;
            continue;
        }
        if ((*type) == '\t' || (*type) == '\n') {
            type++;
            continue;
        }
        if ((*type) == '\r' || (*type) == '\f') {
            type++;
            continue;
        }
    }
}
