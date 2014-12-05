#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

using namespace std;



int main(int argc, char** argv)
{


  string filename = argv[1];
  fstream data;
  string header;
  vector<string> comments;
  vector<string> radardata;
  data.open(filename, fstream::in);
  char buf[300];
  while (data.getline(buf,300))
    {
      if (buf[0]=='>')
	{
	  header=(buf);
	}
      else if (buf[0]==' ')
	{
	  radardata.push_back(buf);
	}
      else
	{
	  comments.push_back(buf);
	}
    }


  cout<<header<<endl;
  for(int i=0;i<comments.size();i++){
    cout<<comments[i]<<endl;}
  int line_number=-1;
  for (int i=0;i<radardata.size();i++){
  cout<<radardata[i]<<endl;
  line_number++;
  }
  cout<<endl;


  cout<<"There are "<<line_number*10<<" lines data in this file"<<endl;

  vector<string> time;
  vector<string> lineindex;
  for (int i=0;i<radardata.size();i++){    
  string dataline=radardata[i];
  istringstream ss(dataline);
  string command;
  ss>>command;
  lineindex.push_back(command);
  ss>>command;
  ss>>command;
  time.push_back(command);
  }


  double min_time=atof(time[0].c_str());
  double max_time=atof(time[line_number].c_str());
  cout<<"The start time is: "<<min_time<<endl;
  cout<<"The end time is :"<<max_time<<endl;
  cout<<"The time resolution of this experiment is: "<<((min_time+max_time)/line_number)<<" hours"<<endl;

    string anyline=radardata[1];
    istringstream ss(anyline);
    string command;
      ss>>command;
      ss>>command;
      double date=atof(command.c_str());
      ss>>command;
      ss>>command;
      double datapoints_oneline=atof(command.c_str());
      ss>>command;
      double sp=atof(command.c_str());
      ss>>command;
      double min_height=atof(command.c_str());
      ss>>command;
      double max_height=atof(command.c_str());
      ss>>command;
      ss>>command;
      string linefeed_po=command;
      ss>>command;
      string gregorian_po=command;
    double point= datapoints_oneline/sp;


    cout<<"The min height is: "<<min_height<<" km"<<endl;
    cout<<"The max height is: "<<max_height<<" km"<<endl;
  cout<<"The range resolution of this experiment is: "<<((min_height+max_height)/point)<<" km"<<endl;
  cout<<"The pointing degree of Linefeed is at: "<<linefeed_po<<" degree"<<endl;
  cout<<"The pointing degree of Gregorian is at: "<<gregorian_po<<" degree"<<endl;     


  int a=0,b=0,c=0,d=0,e=0;
  for (int i=0;i<time.size();i++)
    {
      if (atof(time[i].c_str())<10){
	a++;
        }
      else if (atof(time[i].c_str())<12){
	b++;}
      else if (atof(time[i].c_str())<14){
	c++;}
      else if (atof(time[i].c_str())<16){
	d++;}
      else {e++;}
    }


  cout<<"There are "<<a*10<<" records early than 10:00am."<<endl;
  cout<<"There are "<<b*10<<" records between 10:00am and 12:00am."<<endl;
  cout<<"There are "<<c*10-10<<" records between 12:00am and 2:00pm."<<endl;
  cout<<"There are "<<d*10<<" records between 2:00pm and 4:00pm."<<endl;
  cout<<"There are "<<e*10<<" records later than 4:00pm."<<endl;
  cout<<endl;
  double st;
  double et;


  cout<<"Please enter a time range: "<<endl;
  cout<<"The start time: "<<endl;
  cin>>st;
  cout<<"The end time: "<<endl;
  cin>>et;
  vector<int> line_range;
  int x=0;
  for (int i=0;i<time.size();i++){
    pair<double,double> foo[i];
    foo[i].first=atof(lineindex[i].c_str());
    foo[i].second=atof(time[i].c_str());

    if ((get<1>(foo[i])>st)&&(get<1>(foo[i])<et)){
      line_range.push_back(get<0>(foo[i]));
      x++;}
 }
  cout<<"This range of data are at the lines from "<<line_range[0]<<" to "<<line_range[x-1]<<endl;


  return 0;  
}
