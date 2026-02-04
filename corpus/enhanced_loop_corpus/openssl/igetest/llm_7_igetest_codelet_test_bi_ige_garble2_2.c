#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    matches = 0;
    for (n = 0; n < sizeof(checktext); n += 4) {
        size_t chunk_matches = 0;
        for (unsigned int i = 0; i < 4 && (n + i) < sizeof(checktext); ++i) {
            if (checktext[n + i] == plaintext[n + i])
                chunk_matches++;
        }
        matches += chunk_matches;
    }
}
