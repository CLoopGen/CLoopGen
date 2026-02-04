#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dbuf[5152];
extern  int dlen;
extern int digits;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = (digits + 1) / 2, j = digits - (digits + 1) / 2, val = dlen, count = 0; 
         val && count < digits; 
         ++count, val /= 10, --i, ++j) {
        if (i > 0) {
            dbuf[start + i] = "0123456789"[val % 10];
        }
        if (j > 0 && i != j) {
            int temp_val = dlen;
            for (int k = 0; k < digits - j; ++k) {
                temp_val /= 10;
            }
            dbuf[start + j] = "0123456789"[temp_val % 10];
        }
    }
}
