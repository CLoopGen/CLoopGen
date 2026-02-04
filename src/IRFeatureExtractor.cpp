#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/IR/Dominators.h" 
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Transforms/Vectorize/LoopVectorizationLegality.h"
#include "llvm/Analysis/DemandedBits.h"
#include "llvm/Analysis/ProfileSummaryInfo.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/OptimizationRemarkEmitter.h"
#include "llvm/Analysis/LoopIterator.h"
#include "llvm/Analysis/CFG.h"
#include "llvm/Analysis/ScalarEvolutionPatternMatch.h"


using namespace llvm;

static void collectSupportedLoops(Loop &L, LoopInfo *LI,
                                  OptimizationRemarkEmitter *ORE,
                                  SmallVectorImpl<Loop *> &V) {
  if (L.isInnermost()) {
    LoopBlocksRPO RPOT(&L);
    RPOT.perform(LI);
    if (!containsIrreducibleCFG<const BasicBlock *>(RPOT, *LI)) {
      V.push_back(&L);
      return;
    }
  }
  for (Loop *InnerL : L)
    collectSupportedLoops(*InnerL, LI, ORE, V);
}

struct LoopCarriedDependencyCount {
    unsigned LoadStoreDeps = 0;
    unsigned StoreStoreDeps = 0;
    unsigned StoreLoadDeps = 0;
    unsigned IntrationDeps = 0;

    void printValues(raw_ostream &OS) const {
        OS << LoadStoreDeps << "," << StoreStoreDeps << "," << StoreLoadDeps << "," << IntrationDeps;
    }

    void print(raw_ostream &OS) const {
        OS << "Load-Store Dependencies: " << LoadStoreDeps << "\n";
        OS << "Store-Store Dependencies: " << StoreStoreDeps << "\n";
        OS << "Store-Load Dependencies: " << StoreLoadDeps << "\n";
        OS << "Intration Dependencies: " << IntrationDeps << "\n";
    }
};

struct InstTypeCount {
    unsigned Compute = 0;
    unsigned Load = 0;
    unsigned Store = 0;

    void printValues(raw_ostream &OS) const {
        OS << Compute << "," << Load << "," << Store;
    }

    void print(raw_ostream &OS) const {
        OS << "Compute Instructions: " << Compute << "\n";
        OS << "Load Instructions: " << Load << "\n";
        OS << "Store Instructions: " << Store << "\n";
    }
};

struct LoopAccessStrideCount {
    unsigned ConstantStrides = 0;
    unsigned ContinuousAccess = 0;
    unsigned StridedAccess = 0;
    unsigned UnknownStrides = 0;

    void printValues(raw_ostream &OS) const {
        OS << ConstantStrides << "," << ContinuousAccess << "," << StridedAccess << "," << UnknownStrides;
    }

    void print(raw_ostream &OS) const {
        OS << "Constant Strides: " << ConstantStrides << "\n";
        OS << "Continuous Accesses: " << ContinuousAccess << "\n";
        OS << "Strided Accesses: " << StridedAccess << "\n";
        OS << "Unknown Strides: " << UnknownStrides << "\n";
    }

};

struct LoopFeatures {
    LoopCarriedDependencyCount DepCounts;
    InstTypeCount InstCounts;
    LoopAccessStrideCount StrideCounts;
    size_t canLoopVectorize = 0;
    size_t canOuterLoopVectorize = 2;
    void printValues(raw_ostream &OS) const {
        DepCounts.printValues(OS);
        OS << ",";
        InstCounts.printValues(OS);
        OS << ",";
        StrideCounts.printValues(OS);
        OS << ",";
        OS << canLoopVectorize << ",";
        OS << canOuterLoopVectorize;
    }

    void print(raw_ostream &OS) const {
        OS << "=== Loop Features ===\n";
        OS << "--- Dependency Counts ---\n";
        DepCounts.print(OS);
        OS << "--- Instruction Counts ---\n";
        InstCounts.print(OS);
        OS << "--- Access Stride Counts ---\n";
        StrideCounts.print(OS);
        OS << "Can Loop Vectorize: " << (canLoopVectorize ? "Yes" : "No") << "\n";
        OS << "Can Outer Loop Vectorize: ";
        if (canOuterLoopVectorize == 0)
            OS << "No\n";
        else if (canOuterLoopVectorize == 1)
            OS << "Yes\n";
        else
            OS << "One Level Loop\n";
    }
};


struct IRLoopFeatureAnalysis : public PassInfoMixin<IRLoopFeatureAnalysis> {
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM) {
    if(F.isDeclaration() || !F.getName().starts_with("loop"))
        return PreservedAnalyses::all();

    LoopInfo *LI = &AM.getResult<LoopAnalysis>(F);
    DominatorTree *DT = &AM.getResult<DominatorTreeAnalysis>(F);
    ScalarEvolution *SE = &AM.getResult<ScalarEvolutionAnalysis>(F);
    AliasAnalysis *AA = &AM.getResult<AAManager>(F);
    TargetTransformInfo *TTI = &AM.getResult<TargetIRAnalysis>(F);
    TargetLibraryInfo *TLI = &AM.getResult<TargetLibraryAnalysis>(F);
    AssumptionCache *AC = &AM.getResult<AssumptionAnalysis>(F);
    DemandedBits *DB = &AM.getResult<DemandedBitsAnalysis>(F);
    OptimizationRemarkEmitter *ORE = &AM.getResult<OptimizationRemarkEmitterAnalysis>(F);
    LoopAccessInfoManager *LAIs = &AM.getResult<LoopAccessAnalysis>(F);

    auto &MAMProxy = AM.getResult<ModuleAnalysisManagerFunctionProxy>(F);
    ProfileSummaryInfo *PSI = MAMProxy.getCachedResult<ProfileSummaryAnalysis>(*F.getParent());
    BlockFrequencyInfo *BFI = nullptr;
    if (PSI && PSI->hasProfileSummary())
    BFI = &AM.getResult<BlockFrequencyAnalysis>(F);

    for (const auto &L : *LI) {
        simplifyLoop(L, DT, LI, SE, AC, nullptr, false);
    }

    SmallVector<Loop *, 8> Worklist;

    for(Loop *L : *LI){
        collectSupportedLoops(*L, LI, ORE, Worklist);
    }

    std::vector<LoopFeatures> AllLoopFeatures;

    LoopFeatures LF;
    Loop *outestLoop = nullptr;
    while (!Worklist.empty()) {
        Loop *L = Worklist.pop_back_val();

        LF.StrideCounts = getLoopAccessStrideCount(L, *SE);
        Loop *OutermostLoop =  L->getOutermostLoop();
        if (OutermostLoop != outestLoop) {
            outestLoop = OutermostLoop;
        }else{
            continue;
        }


        DependenceInfo DI = AM.getResult<DependenceAnalysis>(F);
        LF.DepCounts = getLoopCarriedDependencyCount(OutermostLoop, DI);
        LF.InstCounts = getInstTypeCount(OutermostLoop);

        formLCSSARecursively(*L, *DT, LI, SE);

        PredicatedScalarEvolution PSE(*SE, *L);
        LoopVectorizeHints Hints(L, false, *ORE, TTI);
        LoopVectorizationRequirements Requirements;

        LoopVectorizationLegality LVL(L, PSE, DT, TTI, TLI, &F, *LAIs, LI, ORE,
                                &Requirements, &Hints, DB, AC, BFI, PSI, AA);

        if(LVL.canVectorize(false)) {
            LF.canLoopVectorize = 1;
        }

        if(OutermostLoop != L){
            Loop *ParentLoop = L->getParentLoop();
            PredicatedScalarEvolution PSE(*SE, *ParentLoop);
            LoopVectorizeHints Hints(ParentLoop, false, *ORE, TTI);
            LoopVectorizationRequirements Requirements;

            LoopVectorizationLegality LVL(ParentLoop, PSE, DT, TTI, TLI, &F, *LAIs, LI, ORE,
                                    &Requirements, &Hints, DB, AC, BFI, PSI, AA);
            if(LVL.UcananVectorizeOuterLoop()) {
                LF.canOuterLoopVectorize = 1;
            } else {
                LF.canOuterLoopVectorize = 0;
            } 
        }
    
        LF.printValues(llvm::outs());
        llvm::outs() << "\n";
    }

    return PreservedAnalyses::all();
  }


    std::optional<int64_t> getPtrStride(Loop *L, Value *Ptr, Type *PtrType, ScalarEvolution *SE) {
        if (isa<ScalableVectorType>(PtrType)){
                return std::nullopt;
            }

        const SCEV *S = SE->getSCEV(Ptr);

        if(SE->isLoopInvariant(S, L)){
            return 0;
        }

        const SCEVAddRecExpr *AR = dyn_cast<SCEVAddRecExpr>(S);
        if(!AR){
            return std::nullopt;
        }

        if(L != AR->getLoop()){
            return std::nullopt;
        }
        const SCEV *Step =  AR->getStepRecurrence(*SE);
        const APInt *APStepVal;
        if (!SCEVPatternMatch::match(Step, SCEVPatternMatch::m_scev_APInt(APStepVal))) {
            return std::nullopt;
        }
        const auto &DL = L->getHeader()->getDataLayout();
        TypeSize AllocSize = DL.getTypeAllocSize(PtrType);
        int64_t Size = AllocSize.getFixedValue();
        
        std::optional<int64_t> StepVal = APStepVal->trySExtValue();
        if(!StepVal.has_value()){
            return std::nullopt;
        }

        return *StepVal / Size;              
    }

    LoopCarriedDependencyCount getLoopCarriedDependencyCount(Loop *L, DependenceInfo &DI) {
        LoopCarriedDependencyCount LCDCount;
        std::vector<Instruction*> LoadAndStoreInsts;
        for (BasicBlock *BB : L->getBlocks()) {
            for (Instruction &I : *BB) {
                if (auto *SI = dyn_cast<StoreInst>(&I))
                    LoadAndStoreInsts.push_back(SI);
                else if (auto *LI = dyn_cast<LoadInst>(&I))
                    LoadAndStoreInsts.push_back(LI);
            }
        }

        for(size_t i = 0; i < LoadAndStoreInsts.size(); i++){
            for(size_t j = i+1; j < LoadAndStoreInsts.size(); j++){
                Instruction *Src = LoadAndStoreInsts[i];
                Instruction *Dst = LoadAndStoreInsts[j];
                if(auto Dep = DI.depends(Src, Dst, /*PossiblyLoopIndependent=*/false)){
                    if(auto *LI = dyn_cast<LoadInst>(Src)){
                        if(auto *SI = dyn_cast<StoreInst>(Dst)){
                            // Load -> Store
                            if(Dep->isAnti()){
                                LCDCount.LoadStoreDeps++;
                                if(!Dep->isLoopIndependent()){
                                    LCDCount.IntrationDeps++;
                                }
                            }
                        }
                    } else if(auto *SI = dyn_cast<StoreInst>(Src)){
                        if(auto *LI = dyn_cast<LoadInst>(Dst)){
                            // Store -> Load
                            if(Dep->isFlow()){
                                LCDCount.StoreLoadDeps++;
                                if(!Dep->isLoopIndependent()){
                                    LCDCount.IntrationDeps++;
                                }
                            }
                        } else if(auto *SI2 = dyn_cast<StoreInst>(Dst)){
                            // Store -> Store
                            if(Dep->isOutput()){
                                LCDCount.StoreStoreDeps++;
                                if(!Dep->isLoopIndependent()){
                                    LCDCount.IntrationDeps++;
                                }
                            }
                        }
                    }
                }
            }
        }

        return LCDCount;
    }

    InstTypeCount getInstTypeCount(Loop *L) {
        InstTypeCount ITC;
        for (BasicBlock *BB : L->getBlocks()) {
            for (Instruction &I : *BB) {
                if (isa<LoadInst>(&I)) {
                    ITC.Load++;
                } else if (isa<StoreInst>(&I)) {
                    ITC.Store++;
                } else if(
                    isa<BinaryOperator>(&I) ||    
                    isa<CastInst>(&I) ||         
                    isa<GetElementPtrInst>(&I)    
                ){
                    ITC.Compute++;
                } else {
                    continue;
                }
            }
        }
        return ITC;
    }

    LoopAccessStrideCount getLoopAccessStrideCount(Loop *L, ScalarEvolution &SE) {
        LoopAccessStrideCount LASC;
        for (BasicBlock *BB : L->getBlocks()) {
            for (Instruction &I : *BB) {
                Value *Ptr = nullptr;
                if (auto *LI = dyn_cast<LoadInst>(&I)) {
                    Ptr = LI->getPointerOperand();
                } else if (auto *SI = dyn_cast<StoreInst>(&I)) {
                    Ptr = SI->getPointerOperand();
                } else {
                    continue;
                }

                std::optional<int64_t> Stride = getPtrStride(L, Ptr, getLoadStoreType(&I), &SE);
                if (Stride.has_value()) {
                    if (*Stride == 0) {
                        LASC.ConstantStrides++;
                    } else if (*Stride == 1 || *Stride == -1) {
                        LASC.ContinuousAccess++;
                    } else {
                        LASC.StridedAccess++;
                    }
                } else {
                    LASC.UnknownStrides++;
                }
            }
        }
        return LASC;
    }

    Value *getPointerOperand(Instruction *I) {
        if (auto *LI = dyn_cast<LoadInst>(I))
            return LI->getPointerOperand();
        if (auto *SI = dyn_cast<StoreInst>(I))
            return SI->getPointerOperand();
        return nullptr;
    }


};

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "IRLoopFeature", "v0.1",
    [](PassBuilder &PB) {
      PB.registerPipelineParsingCallback(
        [](StringRef Name, FunctionPassManager &FPM, ArrayRef<PassBuilder::PipelineElement>) {
          if (Name == "ir-loop-feature") {
            FPM.addPass(IRLoopFeatureAnalysis());
            return true;
          }
          return false;
        });
    }};
}