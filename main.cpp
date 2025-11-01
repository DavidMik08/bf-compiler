#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

void usage(string name) {
  name.erase(0,2);
  cout << "ERROR: Wrong usage of \"" << name << "\", the correct usage is: " << endl;
  cout << "    ./" << name << " input.bf -<flag> <flag inputs>" << endl << endl;
  cout << "    Available flags are:" << endl;
  cout << "    x - generate x86_64 assembly, no inputs, default option" << endl;
  cout << "    d - generate assembly for my custom CPU, no inputs" << endl;
  cout << "    o - specify an output file, 1 input that specifies the output file, default is out.asm" << endl;
  
}

int main(int argc, char** argv) {
  if (argc < 2) {
    usage(argv[0]);
    return 1;
  }
  ifstream fi(argv[1]);
  if (!fi.is_open()) {
    cout << "ERROR: Can't open file: " << argv[1] << endl;
    return 1;
  }

  string asmType = "x86_64";
  string output = "out.asm";
  for (int i = 2; i < argc; i++) {
    string flag = argv[i];
    flag.erase(0, 1);
    switch (flag[0]) {
    case 'x': asmType = "X86_64";      break;
    case 'd': asmType = "DMCPU";       break;
    case 'o': output = argv[i+1]; i++; break;
    default: cout << "ERROR: flag \'" << argv[i] << "\' not recognised!" << endl; return 1;
    }
  }
  cout << "DEBUG: asmType: "<< asmType << ", output: " << output << endl;
  
  fi.close();
  return 0;
}
