#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    matches = 0;
    for (i = 0; i < sizeof(checktext) * 3; ++i) {
        n = i % sizeof(checktext);
        if ((checktext[n] == plaintext[n]) && (i % 3 == 0))
            ++matches;
    }
}
