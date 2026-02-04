#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character, but still check bounds)
    char *p = port;
    if (p >= port_end) return;
    for (port_end = p; p < port_end && '0' <= p[0] && p[0] <= '9'; p += 2) {
        // Advance port_end to the furthest valid digit seen so far
        port_end = p + 1;
        if (p + 1 >= port_end || !(('0' <= p[1] && p[1] <= '9'))) break;
    }
}
