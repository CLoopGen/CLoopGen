#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum reg_class {
    NO_REGS,
    AREG,
    DREG,
    CREG,
    BREG,
    SIREG,
    DIREG,
    AD_REGS,
    Q_REGS,
    NON_Q_REGS,
    INDEX_REGS,
    LEGACY_REGS,
    GENERAL_REGS,
    FP_TOP_REG,
    FP_SECOND_REG,
    FLOAT_REGS,
    SSE_REGS,
    MMX_REGS,
    FP_TOP_SSE_REGS,
    FP_SECOND_SSE_REGS,
    FLOAT_SSE_REGS,
    FLOAT_INT_REGS,
    INT_SSE_REGS,
    FLOAT_INT_SSE_REGS,
    ALL_REGS,
    LIM_REG_CLASSES
};

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

struct qty {
    int n_refs;
    int freq;
    int birth;
    int death;
    int size;
    int n_calls_crossed;
    int first_reg;
    enum reg_class min_class;
    enum reg_class alternate_class;
    enum machine_mode mode;
    short phys_reg;
    char changes_mode;
};

short *reg_renumber;
int next_qty;
struct qty *qty;
int *reg_next_in_qty;
char *reg_offset;
int i;
int q;

void init_vars() {
    const int data_size = 65536; 

    next_qty = data_size;

    qty = (struct qty *)calloc(next_qty, sizeof(struct qty));
    reg_next_in_qty = (int *)malloc(data_size * sizeof(int));
    reg_offset = (char *)malloc(data_size * sizeof(char));
    reg_renumber = (short *)malloc(data_size * sizeof(short));

    for (int idx = 0; idx < data_size; idx++) {
        qty[idx].phys_reg = (idx % 16) >= 8 ? -1 : (idx % 8); 
        qty[idx].first_reg = (idx % 16) >= 8 ? -1 : idx % (data_size / 16);
        qty[idx].min_class = GENERAL_REGS;
        qty[idx].alternate_class = INDEX_REGS;
        qty[idx].mode = SImode;
        qty[idx].changes_mode = 0;
        qty[idx].n_refs = 1;
        qty[idx].freq = 1;
        qty[idx].birth = 0;
        qty[idx].death = 100;
        qty[idx].size = 4;
        qty[idx].n_calls_crossed = 0;
    }

    for (int idx = 0; idx < data_size; idx++) {
        reg_next_in_qty[idx] = (idx + 1) < data_size ? (idx + 1) : -1;
        reg_offset[idx] = idx % 8;
        reg_renumber[idx] = -1;
    }
}