// Source for AST nodes

#include <vexp.h>


VExprAst::VExprAstPtr VExprAst::MakeConstant(int base, const std::string & lit) {
  return std::make_shared<VExprAstConstant>(base, lit);
}

// # name #
VExprAst::VExprAstPtr VExprAst::MakeSpecialName(const std::string & name) {
  return std::make_shared<MakeVar>(name, true);
}
VExprAst::VExprAstPtr VExprAst::MakeVar(const std::string & name) {
  return std::make_shared<MakeVar>(name, false);
}

VExprAst::VExprAstPtr VExprAst::MakeUnaryAst(voperator op, const VExprAstPtr & c) {
  if (op == voperator::PLUS ||
      op == voperator::MINUS  ||
      op == voperator::L_NEG  ||
      op == voperator::B_NEG  ||
      op == voperator::B_AND  ||
      op == voperator::B_NAND ||
      op == voperator::B_OR   ||
      op == voperator::B_NOR  ||
      op == voperator::B_XOR  ||
      op == voperator::B_EQU      // "^~"|"~^"
    ) {
    return std::make_shared<VExprAst>(op , {c});
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched);
  return NULL;
}



VExprAst::VExprAstPtr VExprAst::MakeBinaryAst(voperator op, const VExprAstPtr & c1, const VExprAstPtr & c2) {
  if (op == voperator::REPEAT     || // {x{a}}
      op == voperator::STAR       || // mul
      op == voperator::PLUS       ||
      op == voperator::MINUS      ||
      op == voperator::ASL        ||
      op == voperator::ASR        ||
      op == voperator::LSL        ||
      op == voperator::LSR        ||
      op == voperator::DIV        ||
      op == voperator::POW        ||
      op == voperator::MOD        ||
      op == voperator::GTE        ||
      op == voperator::LTE        ||
      op == voperator::GT         ||
      op == voperator::LT         ||
      op == voperator::L_NEG      ||
      op == voperator::L_AND      ||
      op == voperator::L_OR       ||
      op == voperator::C_EQ       ||
      op == voperator::L_EQ       ||
      op == voperator::C_NEQ      ||
      op == voperator::L_NEQ      ||
      op == voperator::B_NEG      ||
      op == voperator::B_AND      ||
      op == voperator::B_OR       ||
      op == voperator::B_XOR      ||
      op == voperator::B_EQU      ||
      op == voperator::B_NAND     ||
      op == voperator::B_NOR      ||

      op == voperator::INDEX      ||
      op == voperator::AT
    ) {
    return std::make_shared<VExprAst>(op , {c1,c2});
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched);
  return NULL;
}


VExprAst::VExprAstPtr VExprAst::MakeTernaryAst(voperator op, const VExprAstPtr & c1, const VExprAstPtr & c2, const VExprAstPtr & c3) {
  if (op == voperator::TERNARY || 
      op == RANGE_INDEX ||
      op == STORE_OP
    ) {
    return std::make_shared<VExprAst>(op , {c1,c2,c3});
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched);
  return NULL;
}

VExprAst::VExprAstPtr VExprAst::MakeNaryAst(voperator op, const VExprAstPtrVec & children) {
  // function application & concat 
  if (op == voperator::FUNCTION_APP || 
      op == voperator::CONCAT
    ) {
    return std::make_shared<VExprAst>(op , children);
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched);
  return NULL;
}


