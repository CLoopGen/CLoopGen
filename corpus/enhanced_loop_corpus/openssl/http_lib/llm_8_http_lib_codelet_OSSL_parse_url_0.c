#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t count = 0;
    for (port_end = port; '0' <= *port_end && *port_end <= '9'; port_end++) {
        count += (count + 1) * 2; // Increase arithmetic intensity
    }
    // Introduce auxiliary computation independent of loop bounds
    count *= count + 3;
}
