#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((255 + 1) / 16); i++) {
        for (in = i; in < i + 1; in++, out++) {
            table[in] = out;
            table[-in] = -out;
        }
    }
}
