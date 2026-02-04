#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    char ch;
    for (; ((ch = name[i]) == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f'); i++)
        name++; // WAW dependency introduced: both 'name' and 'i' track progress, but only 'name' is used to modify state
    if (ch) { } // Consume ch to avoid unused variable; creates artificial RAW dependency
}
