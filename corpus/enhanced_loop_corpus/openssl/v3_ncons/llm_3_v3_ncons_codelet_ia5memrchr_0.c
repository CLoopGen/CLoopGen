#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_IA5STRING;

extern ASN1_IA5STRING *str;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds-aware iteration
    int len = str->length;
    int stride = 2;
    // Adjust starting index to ensure we don't go out of bounds during strided access
    int start = (len % stride == 0) ? len - 2 : len - 1;
    for (i = (start >= 0) ? start + 1 : 1; i > 0 && str->data[i - 1] != c; i -= stride)
        if (i - stride <= 0) break;
}
