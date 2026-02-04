#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_matches = 0;
    for (n = 0; n < sizeof(checktext); ++n) {
        unsigned char ct_val = checktext[n];
        unsigned char pt_val = plaintext[n];
        if (ct_val == pt_val)
            local_matches++;
    }
    matches += local_matches;
}
