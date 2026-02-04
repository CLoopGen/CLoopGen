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
    I32 local_len, local_bits = bits;
    char *local_s = s;
    char *local_str = str;
    
    for (local_len = 0; local_len < aint; local_len++) {
        if (local_len & 7)
            local_bits >>= 1;
        else
            local_bits = *local_s++;
        local_str[local_len] = '0' + (local_bits & 1);
    }
    
    // Update globals after loop to eliminate WAW and WAR hazards
    len = local_len;
    bits = local_bits;
    s = local_s;
    str = local_str + aint;
}
