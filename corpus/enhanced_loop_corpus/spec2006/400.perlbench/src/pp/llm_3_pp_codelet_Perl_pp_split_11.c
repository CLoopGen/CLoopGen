#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with bounds checking using pointer arithmetic in steps of 1, but pre-increment check
    char *temp;
    for (m = s, temp = s; m < strend && temp < strend && *temp != '\n'; temp++, m = temp)
        ;
}
