

enum class voperator { 
  STAR,
  PLUS,
  MINUS,
  ASL,
  ASR,
  LSL,
  LSR,
  DIV,
  POW,
  MOD,
  GTE,
  LTE,
  GT,
  LT,
  L_NEG,
  L_AND,
  L_OR,
  C_EQ,
  L_EQ,
  C_NEQ,
  L_NEQ,
  B_NEG,
  B_AND,
  B_OR,
  B_XOR,
  B_EQU,
  B_NAND,
  B_NOR,
  TERNARY,
  /*special ops*/
  FUNCTION_APP,
  CONCAT,
  REPEAT,
   };

class VExprAst {
public:
  typedef std::shared_ptr<VExprAst> VExprAstPtr;
  typedef std::vector<VExprAstPtr> VExprAstPtrVec;
  
  virtual voperator get_op() = 0;
  virtual unsigned get_arity() = 0;
  virtual const VExprAstPtrVec & get_child()  { return child_; } 
  
protected:
  VExprAstPtrVec child_;
  
};
