#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every second character)
    for (st = (char *)suitestr; *st != '\x00'; st += 2) {
        if (*st == ',')
            delim_count++;
        // Handle potential null byte at odd index in case of even-length string
        if (*(st + 1) == ',' && *(st + 1) != '\x00')
            delim_count++;
    }
}
