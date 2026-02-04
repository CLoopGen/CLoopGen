#include <stdio.h>

#include <inttypes.h>

enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};


struct value_data_entry {
    enum machine_mode mode;
    unsigned int oldest_regno;
    unsigned int next_regno;
};


struct value_data {
    struct value_data_entry e[53];
    unsigned int max_value_regs;
};


extern struct value_data *vd;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    int limit = (53 + 1) / 2;
    for (i = 0; i < limit; ++i) {
        int idx1 = i * 2;
        int idx2 = idx1 + 1;

        vd->e[idx1].mode = VOIDmode;
        vd->e[idx1].oldest_regno = idx1;
        vd->e[idx1].next_regno = (~(unsigned int)0);

        if (idx2 < 53) {
            vd->e[idx2].mode = VOIDmode;
            vd->e[idx2].oldest_regno = idx2;
            vd->e[idx2].next_regno = (~(unsigned int)0);
        }
    }
}
