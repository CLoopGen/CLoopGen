#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access on 's' and reversed traversal on 'str'
    // Access every 2nd element of input (strided read), write output in reverse with fixed length
    I32 stride = 2;
    char *s_local = s;
    char *str_end = str + aint;

    for (len = 0; len < aint; len++) {
        if (len & 7)
            bits <<= 1;
        else
            bits = s_local[stride * len];  // Strided read from s

        *(--str_end) = '0' + ((bits & 128) != 0);  // Reverse write to str
    }
    str = str_end;  // Adjust global str pointer to reflect reverse fill
}
