#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 2
    // Access every second element forward, then pass again for odd indices
    // Simulates a strided pattern by splitting into two phases
    char **base_stp = stp;
    char **base_enp = enp;
    for (i = 0; i < 10; i += 2) {
        base_stp[i] = ((void *)0);
        base_enp[i] = ((void *)0);
    }
    for (i = 1; i < 10; i += 2) {
        base_stp[i] = ((void *)0);
        base_enp[i] = ((void *)0);
    }
}
