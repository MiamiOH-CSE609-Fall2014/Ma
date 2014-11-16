#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "parseFastaFile.h"
#include "digramFreqScores.h"
#include "digramFreqMatrix.h"
#include "parseScoringFile.h"
#include "scoreSequence.h"
#include "findHighScore.h"
using namespace std;


int main(int argc, char** argv)
{
  string filename = argv[1];
  tuple<string,vector<string>,string> DNAdata= parseFastaFile(filename);
  cout<<endl;  
cout<<"The whole file contents are :"<<endl;
 cout<<endl;  
string hd = get<0>(DNAdata);
  string sq = get<2>(DNAdata);
  cout<<hd<<endl;
  for (int i=0; i<get<1>(DNAdata).size();i++){
    cout<<get<1>(DNAdata)[i]<<endl;
  }
  cout<<sq<<endl;
  map<string,int> freq = digramFreqScores(sq);
  vector< vector<int> > freqmatrix = digramFreqMatrix(freq);  
  cout<<endl;  
cout<<"The calculated frequence matrix is :"<<endl;
for (vector<int> tempvector: freqmatrix){    
for (int i:tempvector){
      cout<<i<<" ";}   
 cout<<endl;            // This cout part is refer to Lin's work.
      

}

 cout<<"Please input the scoring path: "<<endl;
 string scoring_path;
 cin>>scoring_path;
 vector< vector<int> > scoringMatrix=parseScoringFile(scoring_path);
 cout<<endl;
 cout<<"The scoring Matrix is: "<<endl;
 for(vector<int> temp : scoringMatrix){
   for (int i : temp){
     cout<<i<<" ";}
   cout<<endl;
 }
 cout<<endl;
 cout<<"How many sequences would you like to score? "<<endl;
 int num_seq;
 cin>>num_seq;
 string tpseq;
 vector<string> seqs;
 for(int i=0;i<num_seq;i++){
   cout<<"Please enter the sequence "<<i+1<<endl;
   cin>>tpseq;
   seqs.push_back(tpseq);
 }
 cout<<endl;
 tuple<int,int,string>highscore=findHighScore(sq,seqs,scoringMatrix);
 cout<<"maxSequence is : "<<endl;
 cout<<get<2>(highscore)<<endl;
 cout<<"with the maxScore of : "<<endl;
 cout<<get<1>(highscore)<<endl;
 cout<<" and is at the position of: "<<endl;
 cout<<get<0>(highscore)<<endl;
 return 0;
}
