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
    int i;
    for (i = len; i > 0; i -= 2) {
        if (i - 1 < len && a->data[i - 1])
            break;
        if (i - 2 >= 0 && a->data[i - 2])
            break;
    }
    len = i > 0 ? i - 1 : 0;
}
