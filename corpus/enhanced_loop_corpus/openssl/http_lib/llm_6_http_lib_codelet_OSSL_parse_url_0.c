#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = port;
    char *end = port;
    while (1) {
        char c = *end;
        if (!( '0' <= c && c <= '9' )) break;
        end++;
        p = end; // Introduce artificial WAW dependency on p and end
    }
    port_end = p;
}
