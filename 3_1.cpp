#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int mulThing(string);
int countDigits(string,int);


int main(){
	ifstream fileObj("input.txt");
	string x;
	long int sum=0;
	if (fileObj.is_open()){
		while (getline(fileObj,x))
		{
			sum+=mulThing(x);
		}
		fileObj.close();
	}
	else{
		cerr<<"unable to open input.txt"<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
int countDigits(string x, int startIndex){
	//we need to calc number of digits
	int i = 0;
	bool a = true;
	while(a){
		char temp1 = x[startIndex + i];
		int temp2 = temp1;temp2-=48;
		if((temp2<=9)&&(temp2>=0)){
			i++;continue;
		}
		else{a = false;}
	}
	return i;
}

int mulThing(string x){
	bool stat= true;
	long int sum = 0;
	int leftInt=0,rightInt=0;
	for(int i =0;i<x.size();i++){
		if((x[i]=='d')&&(x[i+1]=='o')&&(x[i+2]=='n')&&(x[i+3]=='\'')&&(x[i+4]=='t')&&(x[i+5]=='(')&&(x[i+6]==')')){
			stat= false;
			i+=6;
			continue;
		}
		if((x[i]=='d')&&(x[i+1]=='o')&&(x[i+2]=='(')&&(x[i+3]==')')){
			stat = true;
			i+=3;
			continue;
		}
		if(stat){
			if((x[i]=='m')&&(x[i+1]=='u')&&(x[i+2]=='l')&&(x[i+3]=='(')&&(stat)){
				char temp1 = x[i+4];
				int temp2 = temp1;
				temp2-=48;//because ascii and string char and conversion system bn all of these is so bad
				if((temp2<=9)&&(temp2>=0)){
					int numL = countDigits(x,i+4);
					leftInt = stoi(x.substr(i+4,numL));
					if((x[i+4+numL]==',')&&(stat)){
						char temp3 = x[i+4+numL+1];
						int temp4 = temp3;temp4-=48;
						if((temp4<=9)&&(temp4>=0)){
							int numR = countDigits(x,i+4+numL+1);
							rightInt = stoi(x.substr(i+4+numL+1, numR));
							if((x[i+4+numL+1+numR]==')')){
								sum+=(leftInt*rightInt);
								cout<<leftInt*rightInt<<" added"<<endl;
							}
						}
					}
				}
			}
		}else{continue;}
	}
	return sum;
}
