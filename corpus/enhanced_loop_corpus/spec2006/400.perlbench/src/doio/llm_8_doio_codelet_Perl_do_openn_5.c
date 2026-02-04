#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 1; i++) {
        while ((*type) == ' ' || (*type) == '\t' || (*type) == '\n' || (*type) == '\r' || (*type) == '\f') {
            type++;
        }
    }
}
