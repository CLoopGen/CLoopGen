#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rawcount = 0;
    for (apos = 0; apos < count2; apos++) {
        char c = buf2[apos];
        int is_valid = (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~');
        if (!is_valid)
            temp_rawcount++;
    }
    rawcount2 += temp_rawcount;
}
