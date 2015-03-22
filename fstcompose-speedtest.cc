#include <time.h>
#include <iostream>
#include <fst/fstlib.h>

using namespace fst;

int main(int argc, char** argv) {
  StdVectorFst* in = StdVectorFst::Read(argv[1]);
  StdVectorFst* lm = StdVectorFst::Read(argv[2]);
  StdVectorFst result;

  std::cerr << "Composing...";
  time_t start, end;
  time (&start);
  Compose(*in, *lm, &result);
  time (&end);
  fprintf(stderr, "Elasped time is %.4lf seconds.\n", difftime(end,start));

  std::cerr << "Writing" << std::endl;
  result.Write("result.fst");
}
