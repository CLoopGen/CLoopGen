#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = (char *)suitestr;
    int temp_count = delim_count; // Introduce WAW dependency by using previous value
    for (int i = 0; ptr[i] != '\x00'; i++) {
        temp_count = (ptr[i] == ',') ? temp_count + 1 : temp_count;
    }
    delim_count = temp_count; // Resolve WAW at loop exit
}
