#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    size_t i;
    matches = 0;
    for (i = sizeof(checktext); i > 0; --i) {
        if (checktext[i - 1] == plaintext[i - 1])
            ++matches;
    }
}
