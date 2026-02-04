#include <iostream>
#include <clang/AST/AST.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/AST/Expr.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Frontend/ASTConsumers.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Tooling/CompilationDatabase.h>
#include <clang/Tooling/Tooling.h>
#include <set>
#include <map>

using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;

struct LoopFeatures {
    int lineCount = 0;
    int depth = 0;
    int scalarCount = 0;
    int array1DCount = 0;
    int array2DCount = 0;
    int array3DCount = 0;
    int pointerCount = 0;
    int branchCount = 0;
    int earlyExitCount = 0;

    std::string location;
    std::set<std::string> visitedVariables;
    std::map<const VarDecl *, size_t> loopVariables;

    void printValue() const {
        llvm::outs() << lineCount << "," << depth << "," << scalarCount << ","
                     << array1DCount << "," << array2DCount << "," << array3DCount << ","
                     << pointerCount << "," << branchCount << "," << earlyExitCount << "\n";
    }
};

class LoopExtractor : public MatchFinder::MatchCallback {
public:
    explicit LoopExtractor(ASTContext *Context) : Context(Context) {}

    void run(const MatchFinder::MatchResult &Result) override {
        if (const ForStmt *FS = Result.Nodes.getNodeAs<ForStmt>("forLoop")) {
            extractLoopFeatures(FS);
        }
    }

    void printValue() {
        for(size_t i = 0; i < features.loops.size(); ++i) {
            const auto& loop = features.loops[i];
            llvm::outs() << "Loop " << i+1 << " at " << loop.location << ":\n";
            llvm::outs() << loop.lineCount << "," << loop.depth << "," << loop.scalarCount << ","
                      << loop.array1DCount << "," << loop.array2DCount << "," << loop.array3DCount << ","
                      << loop.pointerCount << "," << loop.branchCount << "," << loop.earlyExitCount << "\n";
        }
    }

private:
    ASTContext *Context;
    
    struct GlobalLoopFeatures {
        std::vector<LoopFeatures> loops;
    } features;

    bool isLoopVariable(const VarDecl *var, std::map<const VarDecl *, size_t> loopVariables) const {
        return loopVariables.count(var) > 0;
    }

    size_t getLoopDepth(const VarDecl *var, std::map<const VarDecl *, size_t> loopVariables) const {
        auto it = loopVariables.find(var);
        return it != loopVariables.end() ? it->second : 0;
    }

    void extractLoopFeatures(const ForStmt *FS) {
        LoopFeatures loopFeatures;
        
        SourceManager &SM = Context->getSourceManager();
        loopFeatures.location = SM.getSpellingLoc(FS->getBeginLoc()).printToString(SM);
        calculateLoopLines(FS, loopFeatures);
        loopFeatures.depth = calculateMaxDepth(FS, 0, loopFeatures.loopVariables);
        
        extractLoopBodyFeatures(FS, loopFeatures);
        loopFeatures.printValue();
    }

    void calculateLoopLines(const ForStmt *FS, LoopFeatures &loopFeatures) {
        SourceManager &SM = Context->getSourceManager();
        SourceRange range = FS->getSourceRange();
        unsigned startLine = SM.getSpellingLineNumber(range.getBegin());
        unsigned endLine = SM.getSpellingLineNumber(range.getEnd());
        loopFeatures.lineCount = (endLine - startLine + 1);
    }
    
    int calculateMaxDepth(const Stmt *S, int currentDepth, std::map<const VarDecl *, size_t> &loopVariables) {
        if (!S) return currentDepth;
        
        int maxDepth = currentDepth;

        if (isa<ForStmt>(S)) {
            currentDepth++;
            maxDepth = std::max(maxDepth, currentDepth);
            if(auto *FS = dyn_cast<ForStmt>(S)) {
                if (auto *init = FS->getInit()) {
                    if (auto *DS = dyn_cast<DeclStmt>(init)) {
                        for (auto *decl : DS->decls()) {
                            if (auto *VD = dyn_cast<VarDecl>(decl)) {
                                loopVariables[VD] = currentDepth;
                            }
                        }
                    }
                }
            }
        }
        
        for (auto *child : S->children()) {
            if (child) {
                int childDepth = calculateMaxDepth(child, currentDepth, loopVariables);
                maxDepth = std::max(maxDepth, childDepth);
            }
        }
        
        return maxDepth;
    }
    
    void extractLoopBodyFeatures(const Stmt *LoopStmt, LoopFeatures &loopFeatures) {
        std::vector<const Stmt*> stmtsToVisit = {LoopStmt};

        VarDecl *inductionVar = nullptr;
        
        while (!stmtsToVisit.empty()) {
            const Stmt *current = stmtsToVisit.back();
            stmtsToVisit.pop_back();
            
            if (!current) continue;

            if(auto *FS = dyn_cast<ForStmt>(current)) {
                if(auto *inc = FS->getInc()) {
                    if (auto *UO = dyn_cast<UnaryOperator>(inc)) {
                        if (auto *DRE = dyn_cast<DeclRefExpr>(UO->getSubExpr())) {
                            if (auto *VD = dyn_cast<VarDecl>(DRE->getDecl())) {
                                inductionVar = VD;
                            }
                        }
                    } else if (auto *BO = dyn_cast<BinaryOperator>(inc)) {
                        if (auto *DRE = dyn_cast<DeclRefExpr>(BO->getLHS())) {
                            if (auto *VD = dyn_cast<VarDecl>(DRE->getDecl())) {
                                inductionVar = VD;
                            }
                        }
                    }
                }
            }
            
            if (auto *DS = dyn_cast<DeclStmt>(current)) {
                for (auto *decl : DS->decls()) {
                    if (auto *VD = dyn_cast<VarDecl>(decl)) {
                        countVariableType(VD, loopFeatures);
                    }
                }
            } else if (auto *DE = dyn_cast<DeclRefExpr>(current)) {
                if (auto *VD = dyn_cast<VarDecl>(DE->getDecl())) {
                    countVariableType(VD, loopFeatures);
                }
            }
            
            if (isa<IfStmt>(current) || isa<SwitchStmt>(current)) {
                loopFeatures.branchCount++;
            }
            
            if (isa<BreakStmt>(current) || isa<ContinueStmt>(current)) {
                loopFeatures.earlyExitCount++;
            }
            
            for (auto *child : current->children()) {
                if (child) {
                    stmtsToVisit.push_back(child);
                }
            }
        }
    }
    
    void countVariableType(const VarDecl *VD, LoopFeatures &loopFeatures) {
        std::string varName = VD->getNameAsString();
        if (loopFeatures.visitedVariables.count(varName) > 0) {
            return; 
        }
        
        loopFeatures.visitedVariables.insert(varName);
        QualType type = VD->getType();
        
        if (type->isPointerType()) {
            loopFeatures.pointerCount++;
            type = type->getPointeeType();
        }
        
        if (type->isArrayType()) {
            if (auto *arrType = dyn_cast<ArrayType>(type)) {
                unsigned dim = 1; 
                QualType elementType = arrType->getElementType();
                
                while (elementType->isArrayType()) {
                    dim++;
                    if (auto *nestedArr = dyn_cast<ArrayType>(elementType)) {
                        elementType = nestedArr->getElementType();
                    } else {
                        break;
                    }
                }
                
                if (dim == 1) {
                    loopFeatures.array1DCount++;
                } else if (dim == 2) {
                    loopFeatures.array2DCount++;
                } else if (dim >= 3) {
                    loopFeatures.array3DCount++;
                }
            }
        } else {
            loopFeatures.scalarCount++;
        }
    }
};

class LoopFeatureExtractorAction : public ASTFrontendAction {
private:
    LoopExtractor *LE;
    MatchFinder Finder;

public:
    LoopFeatureExtractorAction() : LE(nullptr) {}

    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef) override {
        LE = new LoopExtractor(&CI.getASTContext());
        
        Finder.addMatcher(forStmt(
            unless(hasAncestor(forStmt())),
            hasAncestor(functionDecl(matchesName("loop")))
        ).bind("forLoop"), LE);
        
        return Finder.newASTConsumer();
    }

    void EndSourceFileAction() override {
        return;
    }
};

int main(int argc, const char **argv) {
    llvm::cl::OptionCategory Category("Loop Feature Extraction");

    auto ExpectedParser = CommonOptionsParser::create(argc, argv, Category);
    if (!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }

    CommonOptionsParser &OP = ExpectedParser.get();
    ClangTool Tool(OP.getCompilations(), OP.getSourcePathList());
    return Tool.run(newFrontendActionFactory<LoopFeatureExtractorAction>().get());
}