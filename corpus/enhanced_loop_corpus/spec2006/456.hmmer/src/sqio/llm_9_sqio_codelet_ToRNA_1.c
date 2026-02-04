#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t len = 0;
    const char* temp = seq;
    while (*temp++) len++; // Compute length first

    for (size_t j = 0; j < len; j++) {
        volatile int dummy = 0;
        for (int k = 0; k < 10; k++) {
            dummy += k * k + 3; // Artificial computational load
        }
        if (seq[j] == 'T')
            seq[j] = 'U';
        else if (seq[j] == 't')
            seq[j] = 'u';
    }
}
