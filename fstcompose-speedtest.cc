#include <time.h>
#include <iostream>
#include <fst/fstlib.h>

using namespace fst;

int main(int argc, char** argv) {
  StdVectorFst* in = StdVectorFst::Read(argv[1]);
  StdVectorFst* lm = StdVectorFst::Read(argv[2]);
  StdVectorFst result;

  std::cerr << "Composing...";

  struct timespec tstart={0,0}, tend={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tstart);
  Compose(*in, *lm, &result);
  clock_gettime(CLOCK_MONOTONIC, &tend);
  printf("Elapsed time: %.5f seconds\n",
	 ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
	 ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

  std::cerr << "Writing" << std::endl;
  result.Write("result.fst");
}
