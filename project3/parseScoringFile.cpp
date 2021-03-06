#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "parseScoringFile.h"

using namespace std;

vector< vector<int> > parseScoringFile( string filename){
  fstream scoredata;
  scoredata.open(filename, fstream::in);
  vector< vector<int> > score;
  vector<int> temp;
  char buf[300];
  while (scoredata.getline(buf,300,','))
    {
      temp.push_back(stoi(buf));
      scoredata.getline(buf,300,',');
      temp.push_back(stoi(buf));
      scoredata.getline(buf,300,',');
      temp.push_back(stoi(buf));
      scoredata.getline(buf,300);
      temp.push_back(stoi(buf));
      score.push_back(temp);
      temp.clear();

    }
  return score;
}
