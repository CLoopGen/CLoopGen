#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_end = port;
    char prev_char = '\0';
    for (; '0' <= *temp_end && *temp_end <= '9'; temp_end++) {
        prev_char = *temp_end; // Introduce loop-carried RAW dependency
    }
    port_end = temp_end;
    // Additional use of prev_char to preserve dependency
    if (prev_char == '0') {
        // Dummy operation to ensure data flow is preserved
    }
}
