#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    port_end = port;
    for (; *port_end != '\0'; port_end++) {
        if (*port_end < '0' || *port_end > '9') {
            break;
        }
    }
}
