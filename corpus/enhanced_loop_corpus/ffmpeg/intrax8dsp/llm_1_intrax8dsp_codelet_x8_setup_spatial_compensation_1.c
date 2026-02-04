#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by unrolling the original loop completely
    c = *(ptr + 0); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 1); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 2); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 3); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 4); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 5); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 6); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    c = *(ptr + 7); sum += c; min_pix = ((min_pix) > (c) ? (c) : (min_pix)); max_pix = ((max_pix) > (c) ? (max_pix) : (c));
}
