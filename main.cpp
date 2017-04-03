#include <string.h>
#include <mhash.h>
#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char *argv[]){
  MHASH hash;
  char hashreturn[64];
  if (argv[1] != NULL && argv[2] != NULL){
    //Load file and then hash the test
    std::ifstream infile(argv[1]);
    std::ofstream outfile(argv[2]);
    std::string str;
    while (std::getline(infile,str)){
      hash = mhash_init(MHASH_SHA256);
      mhash(hash, (void*)str.c_str(), str.length());
      mhash_deinit(hash, hashreturn);
      std::cout << hashreturn << std::endl;
      outfile << hashreturn << std::endl;
      }
    return 0;
  }
  std::cout << "Failed" << std::endl;
  return -1;
}
