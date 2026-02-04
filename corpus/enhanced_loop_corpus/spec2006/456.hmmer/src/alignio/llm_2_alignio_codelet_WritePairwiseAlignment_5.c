#include <stdio.h>

#include <inttypes.h>

extern char buf1[61];
extern int count1;
extern int rawcount1;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, forward)
    rawcount1 = 0;
    for (apos = 0; apos < count1; apos += 2) {
        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~'))
            rawcount1++;
    }
    // Handle odd-sized count1 by checking the last element if stride skips it
    if (count1 > 0 && (count1 % 2 == 1)) {
        apos = count1 - 1;
        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~'))
            rawcount1++;
    }
}
