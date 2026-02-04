#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = port;
    port_end = port;
    for (; '0' <= *p && *p <= '9'; p++) {
        port_end = p + 1;
    }
}
