#include <stdio.h>

#include <inttypes.h>

extern unsigned short s[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_s[8];  // Local copy to eliminate global data dependency
    for (i = 2; i < (6 + 3) - 1; i++)
        local_s[i] = 0;         // Eliminate WAW and WAR with external s[] array
    // Write back to original array to preserve observable behavior
    for (i = 2; i < (6 + 3) - 1; i++)
        s[i] = local_s[i];
}
