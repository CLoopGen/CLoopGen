#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const char *whitespace = " \t\n\r\f";
    size_t i = 0;
    for (; (*name); name++) {
        for (i = 0; i < 5; i++) {
            if ((*name) == whitespace[i])
                break;
        }
        if (i == 5)
            break;
    }
}
