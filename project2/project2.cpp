#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

void getGrades(string &g)
{  
  double grades;
  cout<<"Please enter the student's grade: "<<endl;
  getline(cin,g);
    grades=atof(g.c_str());
    if ((grades<0.00)||(grades>100.00))
    {
      throw range_error ("Range error : Score should between 0.00 and 100.00");
    }
}

int main()
{
  string name;
  string score;
  vector<string> s1;
  vector<double> s2;
  int number=0;
  cout<<"Please Enter a student's name or 'none' to quit."<<endl;
  while(getline(cin,name))
    {
      if (name == "none")
        {break;} 
      s1.push_back(name);
      try { getGrades(score);}
      catch (range_error)
	{
	  cout<<"Range Error: The score should between 0.00 to 100.00"<<endl;
          getGrades(score);
	}
      s2.push_back(atof(score.c_str()));
      cout<<"Please Enter a student's name or 'none' to quit."<<endl;
      number+=1;
    }
  cout<<endl;
  double sum=0;
  for (int i=0;i<number;i++)
    { 
      sum+=s2[i];
    }
  double average;
  average = sum/number;
  vector<double> s3;
  for (int i=0;i<number;i++)
    {
      s3.push_back(pow((s2[i]-average),2));
    } 
  double sum_prime=0;
  for (int i=0;i<number;i++)
    { 
      sum_prime+=s3[i];
    }
  double standard_deviation;
  standard_deviation=sqrt(sum_prime/number);
  

  cout<<endl;
  cout<<"Grading Scales: "<<endl;
  double A,B,C,D,F;
  A = average+1.5*standard_deviation;
  B = average+0.5*standard_deviation;
  C = average-0.5*standard_deviation;
  D = average-1.5*standard_deviation;
  cout<<"A above "<<setprecision(1)<<fixed<<min(100.0,A)<<"%"<<endl;
  cout<<"B "<<setprecision(1)<<fixed<<B<<"%-"<<min(100.0,A)<<"%"<<endl;
  cout<<"C "<<setprecision(1)<<fixed<<C<<"%-"<<B<<"%"<<endl;
  cout<<"D "<<setprecision(1)<<fixed<<D<<"%-"<<C<<"%"<<endl;
  cout<<"F below "<<setprecision(1)<<fixed<<D<<"%"<<endl;
  cout<<endl;
  cout<<"Name              Score     Grades"<<endl;
  for (int i=0;i<number;i++)
    {
      cout<<i+1<<"."<<s1[i]<<"          "<<setprecision(1)<<fixed<<s2[i]<<"%     ";
      if ((s2[i]>=100.0)||(s2[i]>=A))
	{
	  cout<<"A"<<endl;
	}
      else if (s2[i]>=B)
	{
	  cout<<"B"<<endl;
	}
      else if (s2[i]>=C)
	{
	  cout<<"C"<<endl;
	}
      else if (s2[i]>=D)
	{
	  cout<<"D"<<endl;
	}
      else {cout<<"F"<<endl;}
    }
  cout<<endl;
  cout<<"Class average = "<<setprecision(2)<<fixed<<average<<"%"<<endl;
  cout<<"Standard Deviation = "<<setprecision(2)<<fixed<<standard_deviation<<endl;
  return 0;

}
