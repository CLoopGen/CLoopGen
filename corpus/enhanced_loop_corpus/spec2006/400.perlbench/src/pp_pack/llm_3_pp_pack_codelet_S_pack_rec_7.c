#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 items;
extern I32 len;
extern int aint;
extern char *aptr;
extern char *str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reversed read access
    char *rev_str = str + aint - 1; // Point to end of string
    for (len = 0; len++ < aint;) {
        if ((*rev_str--) & 1)       // Read backwards from str
            items |= 128;
        if (len & 7)
            items >>= 1;
        else {
            *aptr++ = items & 255;  // Write consecutively forward
            items = 0;
        }
    }
}
