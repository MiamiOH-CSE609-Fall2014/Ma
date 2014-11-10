#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iterator>
#include "digramFreqScores.h"

using namespace std;

map<string,int> digramFreqScores(string s){
  map<string,int> freq={
    {"AA",0},
    {"AC",0},
    {"GT",0},
    {"AG",0},
    {"CC",0},
    {"CA",0},
    {"CG",0},
    {"TT",0},
    {"GG",0},
    {"GC",0},
    {"AT",0},
    {"GA",0},
    {"TG",0},
    {"TA",0},
    {"TC",0},
    {"CT",0}
  };
  string pair;
  for (int i=0;i<s.size()-1;i++)
    {
      //    freq=freq+
++freq[s.substr(i,2)];
    }
  return freq;
}
