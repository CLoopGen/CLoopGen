#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd character)
    char *temp = name;
    for (int i = 0; temp[i]; i += 2) {  // Stride of 2
        if (temp[i] == '\'')
            sep = &temp[i], leaf = &temp[i] + 1;
        else if (temp[i] == ':' && temp[i + 1] == ':')
            sep = &temp[i], leaf = &temp[i] + 2;
    }
}
