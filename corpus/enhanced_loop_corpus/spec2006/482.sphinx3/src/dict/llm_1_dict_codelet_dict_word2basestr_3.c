#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *word;
extern int32 i;
extern int32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len - 2; i > 0; --i) {
        for (int32 j = 0; j < 1; ++j) {  // Artificially nested single-iteration loop
            if (word[i] == '(') {
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
