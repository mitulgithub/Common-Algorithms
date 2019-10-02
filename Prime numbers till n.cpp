#include <iostream>
using namespace std;

int main()
{
	int n;
	bool flag = true;
	cout<<"Enter the number: ";
	cin>>n;
	int cnt = 0;
	
	for(int i=1;i<=n;i++)
	{
		flag = true;
		int div=2;
	while(div<i)
		{
			
			if(i%div==0)
			{
				flag = false;
				break;
			}
				div = div + 1;
		}

	if(i==1)
	{
		continue;
	}
	else 
	{
		if(flag==1)
		{
			cout<<" "<<i<<": "<<char('A'+cnt);
			++cnt;
		}
	}
	
	
}

cout<<endl<<cnt<<endl;

}