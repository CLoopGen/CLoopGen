#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Array (simulate indirect addressing using indices)
    Char *addr_list[1034];
    int i;
    for (i = 0; i < 1034; i++) {
        addr_list[i] = &progNameReally[i];
        if (*addr_list[i] == '\x00') break;
    }
    for (i = 0; i < 1034 && *addr_list[i] != '\x00'; i++) {
        if (*addr_list[i] == '/') {
            progName = addr_list[i] + 1;
        }
    }
}
