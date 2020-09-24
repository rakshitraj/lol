#include <iostream>
#include <vector>

int getNthFib(int n)    {
    std::vector<int> fiblist;
    fiblist.reserve(n);
	
	fiblist.push_back(0);
    fiblist.push_back(1);
	
	for (int i=2; i<n; i++)
	{
		fiblist.push_back(fiblist[i-1] + fiblist[i-2]);
	}
	return fiblist[n-1];
}

long int getNthFibLong(int n)    {
    std::vector<long int> fiblist;
    fiblist.reserve(n);
	
	fiblist.push_back(0);
    fiblist.push_back(1);
	
	for (int i=2; i<n; i++)
	{
		fiblist.push_back(fiblist[i-1] + fiblist[i-2]);
	}
	return fiblist[n-1];
}

int main()
{
    std::cout << "Enter index [1-n]: ";
    int n;
    std::cin >> n;

    if (n<100)  std::cout << "\nn'th Fibonacci number is - " << getNthFib(n);
    else std::cout << "\nn'th Fibonacci number is - " << getNthFibLong(n);
}