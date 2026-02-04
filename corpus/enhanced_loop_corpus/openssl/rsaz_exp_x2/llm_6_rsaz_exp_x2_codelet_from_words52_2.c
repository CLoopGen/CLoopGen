#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp = 0;
    for (i = 0; i < out_len; i++) {
        temp += out[i];      // Introduce RAW dependency: each iteration reads out[i], which affects temp
        out[i] = 0;          // Write after read on out[i]; no WAW or WAR with other iterations due to unique index
    }
    // Final use of temp to prevent dead code elimination (though not observable, maintains semantic validity)
    out[0] = temp ? temp : 1; // Introduces a weak loop-carried dependency via temp, but original zeroing remains primary effect
}
