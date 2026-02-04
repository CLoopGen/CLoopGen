#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (consumed = 0; consumed < in_len; consumed++) {
    *out++ = (*in >> 4);
    *out++ = (*in++ & 15);
}

}
