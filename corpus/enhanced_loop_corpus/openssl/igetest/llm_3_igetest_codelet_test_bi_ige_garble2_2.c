#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal (backward access)
    matches = 0;
    for (n = sizeof(checktext) - 1; n != (unsigned int)(-1); --n)
        if (checktext[n] == plaintext[n])
            ++matches;
}
