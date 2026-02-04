#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated using pointer arithmetic as index source)
    // We simulate indirect access by treating every third byte as an "index" into a shifted view of content
    unsigned char *indices = content;
    int i = 0;
    // Use a fixed bound to avoid infinite loop; assumes content has at least some structure
    for (i = 0; i < 256 && indices[i] != '\x00'; i += 3) {
        c = *(content + (indices[i] % 128)); // Simulate indirect access with bounds control
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
