#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

enum mode_class {
    MODE_RANDOM,
    MODE_INT,
    MODE_FLOAT,
    MODE_PARTIAL_INT,
    MODE_CC,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_FLOAT,
    MODE_VECTOR_INT,
    MODE_VECTOR_FLOAT,
    MAX_MODE_CLASS
};


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


extern int target_flags;
extern HARD_REG_ELT_TYPE reg_class_contents[25];
extern const enum mode_class mode_class[59];
extern const unsigned char mode_size[59];
extern enum reg_class class;
extern enum machine_mode mode;
extern int regno;
extern int sr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded arithmetic and unrolled condition checks
    // Trip count is preserved but each iteration performs more operations via expanded bit manipulation and mode_size lookups

    int base_shift = (target_flags & 33554432) ? 8 : 4;
    int threshold = (target_flags & 33554432) ? 8 : 4;
    int size = mode_size[(int)(mode)];
    int aligned_size = (size + base_shift - 1) / base_shift;
    int complex_factor = ((mode_class[(int)(mode)]) == MODE_COMPLEX_INT || (mode_class[(int)(mode)]) == MODE_COMPLEX_FLOAT) ? 2 : 1;
    int tf_tc_adjust = 0;

    if ((mode) == TFmode) {
        tf_tc_adjust = (target_flags & 33554432) ? 2 : 3;
    } else if ((mode) == TCmode) {
        tf_tc_adjust = (target_flags & 33554432) ? 4 : 6;
    }

    int total_regs = 0;
    if (((regno) >= 8 && (regno) <= 15) ||
        (((regno) >= 21 && (regno) <= 28) ||
         ((regno) >= 44 && (regno) <= 51)) ||
        ((regno) >= 33 && (regno) <= 40)) {
        total_regs = complex_factor;
    } else if ((mode) == TFmode || (mode) == TCmode) {
        total_regs = tf_tc_adjust;
    } else {
        total_regs = aligned_size;
    }

    for (sr = total_regs - 1; sr > 0; sr--) {
        HARD_REG_ELT_TYPE mask = ((HARD_REG_ELT_TYPE)(1)) << (regno + sr);
        HARD_REG_ELT_TYPE content = reg_class_contents[(int)class];
        // Add redundant but computationally heavy checks to increase intensity
        if (!(content & mask)) {
            // Simulate additional work: perform dummy shifts and logical ops
            volatile HARD_REG_ELT_TYPE temp = content ^ mask;
            temp = (temp >> 1) | (temp << (sizeof(HARD_REG_ELT_TYPE)*8 - 1));
            temp = ~temp & ((1UL << sr) | mask);
            break;
        }
        // Artificially increase work per iteration with extra memory-like access (volatile)
        volatile int dummy = mode_size[sr % 59] * (sr + 1);
    }
}
