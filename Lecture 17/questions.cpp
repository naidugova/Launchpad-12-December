#include <iostream>
#include <stack>

using namespace std;

bool balancedParanthesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}else{

			if(s.empty()){
				return false;
			}else{
				s.pop();
			}

		}
	}

	return s.empty();
}

bool isDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch!=')'){
			s.push(ch);
		}else{

			if(s.top()=='('){
				return true;
			}

			while(s.top()!='('){
				s.pop();
			}
			s.pop();

		}
	}

	return false;
}

void nextGreater(int arr[],int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>s.top()){
			int val = s.top();
			s.pop();

			cout<<val<<"->"<<arr[i]<<endl;
		}
		s.push(arr[i]);
	}

	while(!s.empty()){
		int val = s.top();
		s.pop();

		cout<<val<<"->"<<(-1)<<endl;
	}

}


int main(){

	// cout<<balancedParanthesis("(())))((")<<endl;
	// cout<<balancedParanthesis("(())")<<endl;
	// cout<<balancedParanthesis("(())(")<<endl;

	// cout<<isDuplicate("(((a+(b))+c+d))")<<endl;
	// cout<<isDuplicate("((a+b)+(c+d))")<<endl;
	// cout<<isDuplicate("(((a+(b)))+(c+d))")<<endl;

	int arr[] = {2,3,1,5,10,6,12,4};
	int n = 8;

	nextGreater(arr,n);

	return 0;
}