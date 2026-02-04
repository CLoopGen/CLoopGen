#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 items;
extern I32 len;
extern int aint;
extern char *aptr;
extern char *str;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    I32 temp_items = 0;
    for (len = 0; len++ < aint;) {
        char current_char = str[len - 1];
        if (((current_char >= 'A' && current_char <= 'Z') || (current_char >= 'a' && current_char <= 'z'))) {
            temp_items |= (((current_char & 15) + 9) & 15) << 4;
        } else {
            temp_items |= (current_char & 15) << 4;
        }
        if (len & 1) {
            temp_items >>= 4;
        } else {
            *aptr++ = temp_items & 255;
            temp_items = 0;
        }
    }
    items = temp_items; // Break WAW dependency on 'items' inside loop, write once at end
}
