#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *buf;
extern unsigned int i;
extern DES_cblock key;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access buffer backwards from start point)
    // Assume buf points to the beginning of a region, we traverse in reverse over 8-byte window
    // Adjusting pointer arithmetic to simulate reading from buf[7], buf[6], ..., buf[0]
    char *temp_buf = buf + 7;  // Point to hypothetical end of segment
    for (i = 0; i < 8; i++) {
        c = temp_buf[-((int)i)];  // Access as temp_buf[-0], temp_buf[-1], etc. → buf[7], buf[6], ...
        if (!c)
            break;
        key[i] = (c << 1);
    }
}
