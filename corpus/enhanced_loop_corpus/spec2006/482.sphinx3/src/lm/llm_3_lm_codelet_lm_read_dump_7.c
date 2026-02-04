#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 j;
extern int32 k;
extern char *tmp_word_str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, j = 0; i < k; i++){
    int32 idx = (i * 3) % k;
    if (tmp_word_str[idx] == '\x00')
        j++;
}
}
