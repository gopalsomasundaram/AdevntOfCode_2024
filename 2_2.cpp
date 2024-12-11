#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>);
int difference(int,int);
bool diffChecker(vector<int>);
int intCounts(string);
void vecPrint(vector<int>);
bool recVec(vector<int>);

int main(){
	
	ifstream fileObj("input.txt");
	string x;
	vector<int> report;
	int count =0;
	int temp;
	if (fileObj.is_open()){
		while (getline(fileObj,x))
{
			int temp1,temp2;
			istringstream stream(x);
			int reportLen = intCounts(x);
			while(reportLen -- )
			{
				stream>>temp;
				report.push_back(temp);
			}
			if(diffChecker(report)&&check(report)){
				count++;
			}else{
				if(recVec(report)){count++;}
			}
			report.clear();
		}
		fileObj.close();
	}
	else{
		cerr<<"unable to open input.txt"<<endl;
	}
	cout<<count<<endl;
	return 0;
}

bool check(vector<int> x)
{
	int inc = 1;
	int dec = 1;
	int len = x.size();
	for(int i =1;i<len;i++)
	{
		if(x[i-1]>x[i]){
			inc = 0;
		}else if(x[i-1]<x[i]){
			dec = 0;
		}else if (x[i-1]==x[i]){
			inc = 0;
			dec = 0;
		}else{
			cout<<"not possible.....hopefully"<<endl;
		}
	}
	if((inc!=0)||(dec!=0))
	{
		return true;
	}
	else{return false;}
}
int difference(int x,int y){
	if(x>y){
		return (x-y);
	}else if(y>x){
		return (y-x);
	}else{return 0;}
}
bool diffChecker(vector<int> x){
	int flag =1;
	for(int i = 1;i<x.size();i++){
		if(!((difference(x[i-1],x[i]))>=1&&(difference(x[i-1],x[i]))<=3)){
			flag = 0;
		}
	}
	if(flag){
	return true;
	}else{return false;}
}
int intCounts(string a)
{
	int whiteSpace = 0;
	for(string::iterator it=a.begin();it!=a.end();it++)
	{
		if((*it)==' ')
		{
			whiteSpace++;
		}
	}
	return (++whiteSpace);
}
void vecPrint(vector<int> x){
	vector<int>::iterator it;
	for(it=x.begin();it!=x.end();it++){cout<<*it<<" ";}cout<<endl;
}
bool recVec(vector<int> x){
	for(int i = 0; i < x.size();i++){
		vector<int> y =x;
		y.erase(y.begin()+i);
		if(diffChecker(y)&&check(y)){
			return true;break;
		}
	}
	return false;
}
