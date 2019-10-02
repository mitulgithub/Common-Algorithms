#include <iostream>
using namespace std;

int memo[100][100] = {};
int maxProfit(int a[],int beg,int end,int year){
	if(beg>end){
		return 0;
	}

	if(memo[beg][end]!=0) return memo[beg][end]; 
	int profit1 = a[beg]*year + maxProfit(a,beg+1,end,year+1);
	int profit2 = a[end]*year + maxProfit(a,beg,end-1,year+1);
	return memo[beg][end] = max(profit2,profit1);
}

int main(){
	int a[]={2,3,5,1,4};

	int profit = maxProfit(a,0,4,1);
	cout<<profit<<endl;
}