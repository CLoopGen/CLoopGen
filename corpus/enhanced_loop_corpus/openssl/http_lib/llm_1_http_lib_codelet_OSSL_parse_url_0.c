#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (port_end = port; '0' <= *port_end && *port_end <= '9'; )
    for (; '0' <= *port_end && *port_end <= '9'; port_end++)
        ;
}
