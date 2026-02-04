#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 j;
extern int32 k;
extern char *tmp_word_str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, j = 0; i < (k > 0 ? k : 0); i++) {
        char c = tmp_word_str[i];
        j += (c == '\x00') ? 1 : 0;
    }
}
