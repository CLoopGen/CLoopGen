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
    // Variant 2: Indirect memory access using an index array (simulated via offset arithmetic)
    // Simulate an index map: accessing characters in reverse order as indirect pattern
    for (len = 0; len++ < aint;) {
        I32 idx = aint - len;  // Reverse indexing as indirect access pattern
        if (idx >= 0) {
            char c = str[idx];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                items |= (((c & 15) + 9) & 15) << 4;
            else
                items |= (c & 15) << 4;
        } else {
            break;
        }
        if (len & 1)
            items >>= 4;
        else {
            *aptr++ = items & 255;
            items = 0;
        }
    }
}
