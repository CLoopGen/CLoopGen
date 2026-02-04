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
    I32 local_bits = bits;
    char* local_s = s;
    char* local_str = str;
    for (len = 0; len < aint; len++) {
        if ((len & 7) == 0)
            local_bits = *local_s++;
        else
            local_bits <<= 1;
        local_str[len] = '0' + ((local_bits & 128) != 0);
    }
    s = local_s;
    str = local_str + aint;
    bits = local_bits;
}
