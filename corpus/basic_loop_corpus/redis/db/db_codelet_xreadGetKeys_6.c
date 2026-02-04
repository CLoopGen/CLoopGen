#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int pos;
    int flags;
} keyReference;

extern int argc;
extern int i;
extern int num;
extern keyReference *keys;
extern int streams_pos;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = streams_pos + 1; i < argc - num; i++) {
    keys[i - streams_pos - 1].pos = i;
    keys[i - streams_pos - 1].flags = 0;
}

}
