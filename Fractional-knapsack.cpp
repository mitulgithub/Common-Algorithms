#include <bits/stdc++.h> 

using namespace std; 

struct Item 
{ 
	int value, weight; 

	Item(int value, int weight) : value(value), weight(weight) 
	{} 
}; 

bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 

double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 
	for (int i = 0; i < n; i++) 
	{ 
		cout << arr[i].value << " " << arr[i].weight << " : " 
			<< ((double)arr[i].value / arr[i].weight) << endl; 
	} 

	int curWeight = 0; // Current weight in knapsack 
	double finalvalue = 0.0; // Result (value in Knapsack) 

	for (int i = 0; i < n; i++) 
	{ 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	return finalvalue; 
} 

int main() 
{ 
	int W = 0; // Weight of knapsack 
	cout<<"Enter the weight of knapsack"<<endl;
	cin>>W;
	cout<<"Enter the no of items"<<endl
	int n;cin>>n;
	Item arr[];
	for (int i = 0; i < n; ++i)
	 {
	 	cout<<"Value"<<" ";
	 	cin>>arr[i].value;
	 	cout<<"Weight"<<" ";
	 	cin>>arr[i].weight; 
	 } 
	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n); 
	return 0; 
} 
