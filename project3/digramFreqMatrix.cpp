#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "digramFreqMatrix.h"

using namespace std;

vector< vector<int> > digramFreqMatrix(map<string, int> freq){
  vector< vector<int> > freqmatrix;
  vector<int> tvectorA;
  vector<int> tvectorG;
  vector<int> tvectorC;
  vector<int> tvectorT;
  tvectorA.push_back(freq["AA"]);
  tvectorA.push_back(freq["AG"]);
  tvectorA.push_back(freq["AC"]);
  tvectorA.push_back(freq["AT"]);
  freqmatrix.push_back(tvectorA);
  tvectorG.push_back(freq["GA"]);
  tvectorG.push_back(freq["GG"]);
  tvectorG.push_back(freq["GC"]);
  tvectorG.push_back(freq["GT"]);
  freqmatrix.push_back(tvectorG);
  tvectorC.push_back(freq["CA"]);
  tvectorC.push_back(freq["CG"]);
  tvectorC.push_back(freq["CC"]);
  tvectorC.push_back(freq["CT"]);
  freqmatrix.push_back(tvectorC);
  tvectorT.push_back(freq["TA"]);
  tvectorT.push_back(freq["TG"]);
  tvectorT.push_back(freq["TC"]);
  tvectorT.push_back(freq["TT"]);
  freqmatrix.push_back(tvectorT);
  return freqmatrix;
}
