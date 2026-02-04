#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MLZDict {
    int string_code;
    int parent_code;
    int char_code;
    int match_len;
} MLZDict;

extern MLZDict *dict;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 35023; i += 2) {
        dict[i].string_code = -1;
        dict[i].parent_code = -1;
        dict[i].match_len = 0;
        if (i + 1 < 35023) {
            dict[i + 1].string_code = -1;
            dict[i + 1].parent_code = -1;
            dict[i + 1].match_len = 0;
        }
    }
}
