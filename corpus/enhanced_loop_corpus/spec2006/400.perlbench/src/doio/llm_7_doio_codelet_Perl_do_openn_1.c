#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_type = type;
    for (int i = 0; i < 1; i++) {
        local_type++;
        while ((*local_type) == ' ' || (*local_type) == '\t' || (*local_type) == '\n' || (*local_type) == '\r' || (*local_type) == '\f') {
            local_type++;
        }
    }
    type = local_type;
}
