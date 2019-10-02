#include <iostream>
using namespace std;

int factorial(int n,int fact[]){
	if (n==0) return 1;
	
	for (int i = 0; i < n+1; ++i)
	{
		if (i==0)
		{
			fact[i] = 1;
			continue;
		}

		fact[i] = fact[i-1] * i;
	}

	return fact[n];
}

int main(){
	int n;
	cin>>n;
	int fact[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		fact[i] = 0;
	}
	int ans = factorial(n,fact);

	for (int i = 0; i < n+1; ++i)
	{
		cout<<fact[i]<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
}