// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include <algorithm> 
#include <map>

using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;

		int twosum = target;
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			twosum -= (*iter);
			auto element = std::find(iter + 1, nums.end(), twosum);
			if (element != nums.end())
			{
				index.push_back(std::distance(nums.begin(), iter));
				index.push_back(std::distance(nums.begin(), element));
				break;
			}
			else
				twosum = target;
		}
		return index;
	}
};

vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {

	vector<int> items;
	vector<string> dict;
	map<string, int> mapped;
	for (string test : dictionary)
	{
		sort(test.begin(), test.end());
		auto element = mapped.find(test);
		if (element != mapped.end())
			element->second++;
		else
			mapped[test] = 0;
	}
	int NoOftimes = 0;
	for (string que : query)
	{
		sort(que.begin(), que.end());
		NoOftimes = 0;
		auto ele = mapped.find(que);
		if (ele != mapped.end())
			items.push_back(ele->second);
		else
			items.push_back(0);
	}
	return items;
}

template <typename T>
class Test
{
	T* t;
	int size = 1;
	int items = 0;
public:
	Test()
	{
		t = new T[1];
	}
	void push_back(const T& a)
	{
		if (size == items)
		{
			
		}
		t[items++] = a;
	}
};
#include <vector>
using namespace std;

int main()
{
	int ax = 0;
	vector<int> a1;
	a1.push_back(std::ref(ax));
	Test<int> a;
	//int a1= 0;
	//a.push_back(1);
	Solution sol;
	vector<int> test = { 3, 2, 4 };
	sol.twoSum(test, 6);

	// Vector of strings
	std::vector<std::string> vecOfStings{ "ta" , "hello", "hi", "there", "where", "now", "is", \
											"that" , "hi" , "where", "at", "no", "yes", "at" };
	std::vector<std::string> vecOfSting{ "ta" , "hello"};
	//std::move(vecOfSting);
	std::rotate(vecOfSting.begin(), vecOfSting.begin() + 1, vecOfSting.end());
	stringAnagram(vecOfStings, vecOfSting);
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
