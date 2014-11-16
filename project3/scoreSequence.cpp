#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "scoreSequence.h"

using namespace std;

pair<int, int> scoreSequence(string haystack,string needle, vector< vector<int>> scoring_m){
  pair<int,int> maxscore={0,0};
  map<char,int> scoreindex={
    {'A',0},
    {'G',1},
    {'C',2},
    {'T',3}};
  int score=0;
  string words;
  for (int i=0;i<haystack.length()-needle.length()+1;i++){
    score=0;
    words=haystack.substr(i,needle.length());
    for (int i=0;i<needle.length();i++){
      score=score+scoring_m[scoreindex[words[i]]][scoreindex[needle[i]]];
    }
    if(score>=maxscore.second){
      maxscore.first=i;
      maxscore.second=score;
    }
  }
    return maxscore;
}
