// Source for AST nodes

#include <vexp.h>
#include <cassert>

namespace verilog_expr {

VExprAst::VExprAstPtr VExprAst::MakeConstant(int base, int width, const std::string & lit) {
  return std::make_shared<VExprAstConstant>(base, width, lit);
}

// # name #
VExprAst::VExprAstPtr VExprAst::MakeSpecialName(const std::string & name) {
  return std::make_shared<VExprAstVar>(name, true);
}
VExprAst::VExprAstPtr VExprAst::MakeVar(const std::string & name) {
  return std::make_shared<VExprAstVar>(name, false);
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
    VExprAstPtrVec tmp({c});
    return std::make_shared<VExprAst>(op , tmp);
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched, "N-ary not matched in MakeUnaryAst");
  return NULL;
}


VExprAst::VExprAstPtr VExprAst::MakeUnaryParamAst(voperator op, const VExprAstPtr & c, const std::vector<int> & param) {
  if (op == voperator::DELAY     // "^~"|"~^"
    ) {
    VExprAstPtrVec tmp({c});
    auto tmpptr = std::make_shared<VExprAst>(op , tmp);
    tmpptr->parameter_ = param; // copy parameters
    return tmpptr;
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched, "N-ary not matched in MakeUnaryParamAst");
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
    VExprAstPtrVec tmp({c1,c2});
    return std::make_shared<VExprAst>(op , tmp);
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched, "N-ary not matched in MakeBinaryAst");
  return NULL;
}


VExprAst::VExprAstPtr VExprAst::MakeTernaryAst(voperator op, const VExprAstPtr & c1, const VExprAstPtr & c2, const VExprAstPtr & c3) {
  if (op == voperator::TERNARY || 
      op == voperator::RANGE_INDEX ||
      op == voperator::IDX_PRT_SEL_PLUS ||
      op == voperator::IDX_PRT_SEL_MINUS ||
      op == voperator::STORE_OP
    ) {
    VExprAstPtrVec tmp({c1,c2,c3});
    return std::make_shared<VExprAst>(op , tmp);
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched, "N-ary not matched in MakeTernaryAst");
  return NULL;
}

VExprAst::VExprAstPtr VExprAst::MakeNaryAst(voperator op, const VExprAstPtrVec & children) {
  // function application & concat 
  if (op == voperator::FUNCTION_APP || 
      op == voperator::CONCAT
    ) {
    return std::make_shared<VExprAst>(op , children);
  }
  throw VexpException(ExceptionCause::OpNaryNotMatched, "N-ary not matched in MakeNaryAst");
  return NULL;
}

std::vector<std::string> voperator_str_vec = {
  "STAR", // mul
  "PLUS",
  "MINUS",
  "ASL",
  "ASR",
  "LSL",
  "LSR",
  "DIV",
  "POW",
  "MOD",
  "GTE",
  "LTE",
  "GT",
  "LT",
  "L_NEG",
  "L_AND",
  "L_OR",
  "C_EQ",
  "L_EQ",
  "C_NEQ",
  "L_NEQ",
  "B_NEG",
  "B_AND",
  "B_OR",
  "B_XOR",
  "B_EQU",
  "B_NAND",
  "B_NOR",
  "INDEX", // [idx] operator  A[i1][i2] -> index(index(A,i1),i2)   A[i1[i2]]  index(A, index(i1,i2))
  "RANGE_INDEX", // [i1:i2] ternary
  "IDX_PRT_SEL_PLUS", // [i1:+i2] ternary
  "IDX_PRT_SEL_MINUS", // [i1:-i2] ternary
  "STORE_OP", // A:<3>:5:<4>:6:<5>:7  (not supported yet)
  "AT",
  "TERNARY",
  /*special ops*/
  "FUNCTION_APP",
  "CONCAT",
  "REPEAT",
  /*Placeholder*/
  "MK_CONST",
  "MK_VAR",

  "DELAY"
};

std::ostream & operator<<(std::ostream & os, const VExprAst::VExprAstPtr & obj) {
  if (obj) {
    unsigned idx = static_cast<unsigned>( obj->get_op() );
    os << "(";
    if (idx < voperator_str_vec.size())
      os << voperator_str_vec.at(idx);
    else
      os << "unknown_op";
    os << " ";

    if (! (obj->parameter_.empty())) {
      for (const auto & p : obj->parameter_)
        os << ":"<<p<<" ";
    }

    if (obj->is_var()) {
      auto vptr = VExprAstVar::cast_ptr(obj);
      assert(vptr);
      bool spec = vptr->get_name().second;
      os << (spec?"#":"")  << vptr->get_name().first  << (spec?"#":"")  ;
    } else if (obj->is_constant()) {
      auto cptr = VExprAstConstant::cast_ptr(obj);
      assert(cptr);
      int base; int width; std::string lit;
      std::tie(base, width, lit) = cptr->get_constant();
      os << "base" << base << ",width" << width <<"," << lit;
    } else {
      // traverse the child
      for (const auto & child : obj->get_child())
        os << child <<" ";
    }

    return os << ")";
  }
  // else
  return (os << "(NULL)");
} // operator<<

// -----------------------------------------------------------------


bool Attribute::AddAttribute(const std::string & name, const VExprAstPtr & exp) {
  bool not_overwrite = attrib_.find(name) == attrib_.end();
  attrib_.insert(std::make_pair(name, exp));
  return not_overwrite;
}

void Attribute::Append(const Attribute & other) {
  for (const auto & n_v_pair : other.attrib_) {
    attrib_.insert(std::make_pair(n_v_pair.first, n_v_pair.second));
  }
}


int width_to_int(const std::string & s) { // convert width to int
  try {
    return std::stoi(s, NULL, 10);
  } catch (const std::exception& e) {
    return 0;
  }
}

} // namespace verilog_expr
