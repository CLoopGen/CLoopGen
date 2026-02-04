#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 j;
extern int32 k;
extern char *tmp_word_str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < k; i += 2) {
        int32 cond1 = (tmp_word_str[i] == '\x00');
        j += cond1;
        if (i + 1 < k) {
            int32 cond2 = (tmp_word_str[i + 1] == '\x00');
            j += cond2;
        }
    }
}
