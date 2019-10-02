#include <iostream>
using namespace std;
void insertElement(int a[],int n){
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
}
int binarySearch(int a[],int n, int find){
	int beg,end,mid;
	beg = 0;
	end = n-1;
	
	int key = find;
	while(beg<=end){
	mid = (beg+end)/2;
	if(key==a[mid]){
		return mid;
	}
	else{
		
			if(a[mid]>key){
				end = mid-1;
			}
			else{
				beg = mid + 1;
			}
		
	}
}
	return -1;
}

int main(){
	int a[10];
	int n;
	cin>>n;
	insertElement(a,n);
	int find;
	cin>>find;
	 int ans = binarySearch(a,n,find);
	 cout<<ans;
	
}