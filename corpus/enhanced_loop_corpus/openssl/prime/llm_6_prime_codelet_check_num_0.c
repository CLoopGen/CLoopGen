#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = 0;
    while (('0' <= s[temp_i] && s[temp_i] <= '9') || ('A' <= s[temp_i] && s[temp_i] <= 'F') || ('a' <= s[temp_i] && s[temp_i] <= 'f')) {
        temp_i++;
    }
    i = temp_i;
}
