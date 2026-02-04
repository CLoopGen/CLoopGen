#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    const char *volatile ptr = name;
    for (; ((c = *ptr) == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'); ptr++)
        ;
    __asm__ volatile("" : "+r"(ptr) : : "memory");
    name = (char *)ptr;
}
