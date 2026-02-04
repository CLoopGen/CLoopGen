#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t residue;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[16] = {0};
    // Introduce temporary accumulation to create intra-loop WAW and WAR dependencies
    // Eliminate direct write to ivec until after loop; removes RAW/WAR on ivec
    for (size_t i = 0; i < residue; ++i)
        temp[i] = ivec[i] ^ in[i];
    // Now apply accumulated result back to ivec (no loop-carried dependency)
    for (size_t i = 0; i < residue; ++i)
        ivec[i] = temp[i];
}
