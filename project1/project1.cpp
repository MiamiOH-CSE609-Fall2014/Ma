#include <iostream>
using namespace std;
int main()
{
  
  int row1,row2,col1,col2;
  cout<<"Input the row number of Matrix1"<<endl;
  cin>>row1;
  cout<<"Input the colum number of Matrix1"<<endl;
  cin>>col1;
  cout<<"Input the row number of Matrix2"<<endl;
  cin>>row2;
  cout<<"Input the colum number of Matrix2"<<endl;
  cin>>col2;
  if (col1!=row2)
    {
      cout<<"Invalid Input"<<endl;
      return 1;
}
  else {
    cout<<"Input the first Matrix"<<endl;
    int M1[row1][col1],M2[row2][col2],M3[row1][col2];
    for (int i=0;i<row1;i++){
      for (int j=0;j<col1;j++){
	cin>>M1[i][j];    }}
    cout<<"Input the second Matrix"<<endl;
  for (int i=0;i<row2;i++){
    for (int j=0;j<col2;j++){
      cin>>M2[i][j];    }}
  for (int i=0;i<row1;i++){
    for (int j=0;j<col2;j++){
      M3[i][j]=0;
      for (int k=0;k<col1;k++){
	M3[i][j]+=M1[i][k]*M2[k][j];
      }
    }
  }
  cout<<"The first Matrix is: "<<endl;
  for (int i=0;i<row1;i++){
    for (int j=0;j<col1;j++){
      cout<<M1[i][j]<<" ";}
    cout<<endl;}
  cout<<"The Sencond Matrix is: "<<endl;
  for (int i=0;i<row2;i++){
    for (int j=0;j<col2;j++){
      cout<<M2[i][j]<<" ";}
    cout<<endl;}

  cout<<"The Multiplication  Matrix is: "<<endl;
  for (int i=0;i<row1;i++){
    for (int j=0;j<col2;j++){
      cout<<M3[i][j]<<" ";}
    cout<<endl;}
  }
  return 0;
}
