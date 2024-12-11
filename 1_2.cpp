#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream fileObj("input.txt");
	string x;
	vector<int>::iterator itr1;
	vector<int>::iterator itr2;
	vector<int>::iterator itr3;
	vector<int> x1;
	vector<int> x2;
	vector<int> countList;
	int sum = 0;
	if (fileObj.is_open()){
		while (getline(fileObj,x))
		{
			int temp1,temp2;
			istringstream stream(x);
			stream >> temp1 >> temp2;
			x1.push_back(temp1);
			x2.push_back(temp2);
			countList.push_back(0);
		}
		fileObj.close();
	}
	else{
		cerr<<"unable to open input.txt"<<endl;
	}
	itr3=countList.begin();
	for(itr1=x1.begin();itr1!=x1.end();itr1++)
	{
		for(itr2=x2.begin();itr2!=x2.end();itr2++)
		{
			if((*itr1) == (*itr2))
			{
				(*itr3)+=1;
			}
		}
		sum+=((*itr1)*(*itr3));
		itr3++;
	}
	itr1 = x1.begin();
	itr2 = x2.begin();
	itr3 = countList.begin();
	while(itr1!= x1.end())
	{
		cout<<*itr1<<"\t"<<*itr2<<"\t"<<*itr3<<endl;
		itr1++;
		itr2++;
		itr3++;
	}
	cout<<sum<<endl;
	return 0;
}
