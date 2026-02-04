#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_UNIVERSALSTRING;

extern ASN1_UNIVERSALSTRING *s;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp_p = p;
    for (i = 0; i < s->length; i += 4) {
        // Remove direct modification of original 'p' inside loop body, eliminate loop-carried dependency on 'p'
        if ((temp_p[0] != '\x00') || (temp_p[1] != '\x00') || (temp_p[2] != '\x00'))
            break;
        else
            temp_p += 4;
    }
    // Update global 'p' only after loop exits (breaks RAW dependency across iterations)
    p = temp_p;
}
