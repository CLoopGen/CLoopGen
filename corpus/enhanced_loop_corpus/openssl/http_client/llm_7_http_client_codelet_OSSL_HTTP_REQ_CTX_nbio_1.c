#include <stdio.h>

#include <inttypes.h>

extern int i;
extern long n;
extern size_t resp_len;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_resp = 0;
    unsigned char *local_p = p;
    for (i = 0; i < n; i++) {
        local_resp = (local_resp << 8) | local_p[i];
    }
    resp_len = local_resp;
    p += n;
}
