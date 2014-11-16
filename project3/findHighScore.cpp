#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "scoreSequence.h"
#include "findHighScore.h"
using namespace std;

tuple<int,int, string> findHighScore(string haystack,vector<string> needle,vector< vector<int>> scoring_m){
    tuple<int, int, string> highscore;
    pair<int,int> score;
    // score=scoreSequence(haystack,needle.at(i),scoring_m);
    // score.first=get<0>(highscore);
    // score.second=get<1>(highscore);
    // needle[0]=get<2>(highscore);
    for(int i=0;i<needle.size();i++){
      score=scoreSequence(haystack,needle[i],scoring_m);
      if (score.second>get<1>(highscore)){

       get<0>(highscore)=score.first;
       get<1>(highscore)=score.second;
       get<2>(highscore)= needle[i];
      }
    }
    return highscore;
  }
