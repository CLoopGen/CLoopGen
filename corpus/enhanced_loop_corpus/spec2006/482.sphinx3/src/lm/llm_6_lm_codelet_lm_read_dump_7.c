#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 j;
extern int32 k;
extern char *tmp_word_str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_j = 0;
    for (i = 0; i < k; i++) {
        temp_j += (tmp_word_str[i] == '\x00') ? 1 : 0;
    }
    j = temp_j;
}
