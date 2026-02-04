#include <stdio.h>

#include <inttypes.h>

extern size_t inlen;
extern size_t i;
extern int result;
extern  unsigned char *add;
extern unsigned char carry;
extern unsigned char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = inlen; i > 0; i--) {
        unsigned char local_carry = carry;
        size_t offset = i - 1;
        int local_result = d[-(long)offset] + add[-(long)offset] + local_carry;
        carry = (unsigned char)(local_result >> 8);
        d[-(long)offset] = (unsigned char)(local_result & 255);
    }
    // Introduce a finalization step with no loop-carried dependency on d/add pointers
    i = 0;
}
