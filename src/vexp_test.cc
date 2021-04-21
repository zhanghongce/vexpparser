#include "interpreter.h"

#include <iostream>
#include <sstream>

using namespace std;

int main() {
  Vexp::Interpreter intp;
  stringstream ss;
  ss << "i0.a +a.b*4'd8 + (abc+1)@(~t.t0)*a@b##1";
  intp.switchInputStream(&ss);
  try{
    intp.parse();
  } catch (verilog_expr::VexpException &e) {
    cout << "AST constructor error:" << e.msg_ << endl;
  }
  cout << intp.str() << endl;

  return 0;
}
