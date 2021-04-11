#include "interpreter.h"

#include <iostream>
#include <sstream>

using namespace std;
using namespace Vexp;

int main() {
  Interpreter intp;
  stringstream ss;
  ss << "i0.a +a.b*4'd8 + (abc+1)@(~t.t0)";
  intp.switchInputStream(&ss);
  intp.parse();
  cout << intp.str() << endl;

  return 0;
}
