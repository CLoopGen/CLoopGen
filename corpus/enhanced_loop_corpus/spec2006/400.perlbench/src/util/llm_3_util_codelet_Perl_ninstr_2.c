#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated using pointer arithmetic as proxy)
    // We simulate indirect access by treating 'big' as a base and accessing elements in non-linear fashion
    // Here we use a pseudo-indirect pattern: access big[i] then big[i+3], increasing irregularity.
    char *local_big = big;
    char *local_little = little;
    int i = 0;
    int stride = 3;
    for (x = local_big, s = local_little; s < littleend && (s + i) < littleend; ) {
        if (*(s + i) != *(x + i)) {
            s = s + i - 1;
            break;
        }
        i += (i % 2 == 0) ? 1 : stride;  // Alternate between small and large strides (1, 3, 4, 7...)
        if ((s + i) >= littleend) {
            break;
        }
    }
}
