#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_out = out; // Eliminate potential WAW/WAR with external 'out'
    for (int i = in; i <= 255; i++) {
        table[i] = local_out;
        if (i > 0) { // Avoid writing table[0] twice
            table[-i] = -local_out;
        }
    }
    // No loop-carried dependency; all iterations independent
}
