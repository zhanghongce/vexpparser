// Header for AST nodes
// Hongce Zhang (hongcez@princeton.edu)

#ifndef _VEXPPARSER_VEXP_H_
#define _VEXPPARSER_VEXP_H_

#include <memory>
#include <vector>
#include <string>


enum class ExceptionCause { 
  OpNaryNotMatched, //
};

class VexpException {
public:
  VexpException( ExceptionCause cause, const std::string & msg ) : cause_ ( cause ), msg_(msg);

  const ExceptionCause cause_;
  const std::string msg_;
};


enum class voperator { 
  STAR, // mul
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
  INDEX, // [idx] operator  A[i1][i2] -> index(index(A,i1),i2)   A[i1[i2]]  index(A, index(i1,i2))
  RANGE_INDEX, // [i1:i2] ternary
  STORE_OP, // A:<3>:5:<4>:6:<5>:7  (not supported yet)
  AT,

  TERNARY,
  /*special ops*/
  FUNCTION_APP,
  CONCAT,
  REPEAT,
  /*Placeholder*/
  MK_CONST,
  MK_VAR
   };

class VExprAst {
public:
  typedef std::shared_ptr<VExprAst> VExprAstPtr;
  typedef std::vector<VExprAstPtr> VExprAstPtrVec;
  
  voperator get_op() { return op_; }
  unsigned get_child_cnt() { return child_.size() ; }
  virtual const VExprAstPtrVec & get_child()  { return child_; } 

  // factory function -- do the checking here
  static VExprAstPtr MakeConstant(int base, const std::string & lit);
  static VExprAstPtr MakeSpecialName(const std::string & name); // # name #
  static VExprAstPtr MakeVar(const std::string & name); // hierarchy names?
  static VExprAstPtr MakeUnaryAst(voperator op, const VExprAstPtr & c);
  static VExprAstPtr MakeBinaryAst(voperator op, const VExprAstPtr & c1, const VExprAstPtr & c2);
  static VExprAstPtr MakeTernaryAst(voperator op, const VExprAstPtr & c1, const VExprAstPtr & c2, const VExprAstPtr & c3);
  static VExprAstPtr MakeNaryAst(voperator op, const VExprAstPtrVec & children);

protected:
  VExprAst(voperator op, const VExprAstPtrVec & c) : op_(op) , child_(c) {}

  voperator op_;
  VExprAstPtrVec child_;
};

class VExprAstConstant : public VExprAst{
  friend class VExprAst;
protected:
  VExprAstConstant(int base, const std::string & lit) : VExprAst(voperator::MK_CONST, {}), base_(base), lit_ (lit);
  int base_; // 0 (real number) , 2,4,8, 10,16
  std::string lit_; // the actual number part
};

class VExprAstVar : public VExprAst {
  friend class VExprAst;
protected:
  VExprAstVar(const std::string & name, bool is_special_name) : VExprAst(voperator::MK_VAR, {}), name_(name), is_special_name_(is_special_name);
  std::string name_;
  bool is_special_name_;
};

#endif // _VEXPPARSER_VEXP_H_
