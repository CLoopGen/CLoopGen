#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_BIT_STRING;

extern ASN1_BIT_STRING *a;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int i;
    for (i = (len % stride == 0) ? len - stride : len - (len % stride); i >= 0; i -= stride) {
        if (a->data[i])
            break;
    }
    for (; len > i; len--) {
        if (a->data[len - 1])
            break;
    }
}
