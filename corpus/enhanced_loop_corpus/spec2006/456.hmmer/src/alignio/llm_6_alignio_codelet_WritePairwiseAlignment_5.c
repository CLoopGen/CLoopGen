#include <stdio.h>

#include <inttypes.h>

extern char buf1[61];
extern int count1;
extern int rawcount1;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_count = 0;
    for (int i = 0; i < count1; i++) {
        char c = buf1[i];
        if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')) {
            temp_count++;
        }
    }
    rawcount1 += temp_count;
}
