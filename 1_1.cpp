#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

long int difference (long int x, long int y)
{
	if(x>y)
	{
		return x-y;
	}
	else if(x==y)
	{
		return 0;
	}
	else
	{
		return y-x;
	}
}

int main(){
	
	ifstream fileObj("input.txt");
	string x;
	vector<int>::iterator itr1;
	vector<int>::iterator itr2;
	vector<int> x1;
	vector<int> x2;
	long int sum=0;
	if (fileObj.is_open()){
		while (getline(fileObj,x))
		{
			int temp1,temp2;
			istringstream stream(x);
			stream >> temp1 >> temp2;
			x1.push_back(temp1);
			x2.push_back(temp2);
		}
		fileObj.close();
	}
	else{
		cerr<<"unable to open input.txt"<<endl;
	}
	sort(x1.begin(),x1.end());
	sort(x2.begin(),x2.end());
	itr1=x1.begin();
	itr2=x2.begin();
	while(itr1!=x1.end()&&itr2!=x2.end())
	{
		cout<<*itr1<<"   "<<*itr2<<endl;
		itr1++;
		itr2++;
	}
	itr1=x1.begin();
	itr2=x2.begin();
	while(itr1!=x1.end()||itr2!=x2.end())
	{
		sum+=difference(*itr1,*itr2);
		itr1++;
		itr2++;
	}
	cout<<sum<<endl;
	return 0;
}
