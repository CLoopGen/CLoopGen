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
    I32 temp_items = 0;
    for (len = 0; len < aint; len++) {
        char c = str[len];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            temp_items |= ((c & 15) + 9) & 15;
        } else {
            temp_items |= (c & 15);
        }
        if (len & 1) {
            temp_items <<= 4;
        } else {
            aptr[items] = temp_items & 255;
            items++;
            temp_items = 0;
        }
    }
    if ((aint & 1) == 0 && aint > 0) {
        aptr[items] = temp_items & 255;
        items++;
    }
}
