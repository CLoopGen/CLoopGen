#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *string;
extern  char *reject;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern with step size of 2 (simulated unrolling effect)
    // Replaces nested loops and while-like behavior using only for-loops and conditional increments
    int len = 0;
    if (string) {
        while (string[len]) len++;
    }
    for (i = 0; i < len; ) {
        if (i + 1 < len && string[i] == '/' && string[i + 1] == '*') {
            i += 2;
            for (; i < len - 1; i++) {
                if (string[i] == '*' && i + 1 < len && string[i + 1] == '/') {
                    i += 2;
                    break;
                }
            }
        } else if (i + 1 < len && string[i] == '/' && string[i + 1] == '/') {
            i += 2;
            for (; i < len; i++) {
                if (string[i] == '\n') {
                    i++;
                    break;
                }
            }
        } else {
            int found = 0;
            int rej_len = 0;
            if (reject) {
                while (reject[rej_len]) rej_len++;
            }
            for (j = 0; j < rej_len; j++) {
                if (string[i] == reject[j]) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
            i++;
        }
    }
}
