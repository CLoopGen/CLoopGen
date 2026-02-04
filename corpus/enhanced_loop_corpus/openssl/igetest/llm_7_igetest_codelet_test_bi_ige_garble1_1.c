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
        size_t local_matches = 0;
        for (unsigned int i = 0; i < 4 && (n + i) < sizeof(checktext); ++i) {
            if (checktext[n + i] == plaintext[n + i])
                local_matches++;
        }
        matches += local_matches;
    }
}
