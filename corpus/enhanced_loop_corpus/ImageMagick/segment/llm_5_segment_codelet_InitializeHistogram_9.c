#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int Blue;
extern  int Green;
extern  int Red;
extern ssize_t **histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 255; i++) {
    ssize_t *r_row = histogram[Red];
    ssize_t *g_row = histogram[Green];
    ssize_t *b_row = histogram[Blue];
    
    r_row[i] = 0;
    g_row[i] = 0;
    b_row[i] = 0;
}
}
