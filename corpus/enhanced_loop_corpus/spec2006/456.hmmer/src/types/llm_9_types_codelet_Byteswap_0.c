#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 0;
    int end = nbytes - 1;
    while (start < end) {
        byte = swap[start];
        swap[start] = swap[end];
        swap[end] = byte;
        start++;
        end--;
    }
}
