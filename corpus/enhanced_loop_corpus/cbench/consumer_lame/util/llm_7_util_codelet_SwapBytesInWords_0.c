#include <stdio.h>

#include <inttypes.h>

extern short *loc;
extern int words;
extern int i;
extern short thisval;
extern char *dst;
extern char *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short *temp_array[64];
    short val_array[64];
    int batch = 64;
    for (i = 0; i < words; i += batch) {
        int j;
        int limit = (i + batch < words) ? i + batch : words;
        for (j = i; j < limit; j++) {
            short *current = loc + j;
            val_array[j - i] = *current;
            temp_array[j - i] = current;
        }
        for (j = i; j < limit; j++) {
            char *dst_ptr = (char *)temp_array[j - i];
            dst_ptr[0] = src[1];
            dst_ptr[1] = src[0];
        }
    }
}
