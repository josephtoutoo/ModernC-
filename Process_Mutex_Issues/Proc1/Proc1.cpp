// Proc1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
	std::cout << "T1 started" << std::endl;
	// Create a mutex with no initial owner

	HANDLE ghMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		L"UnanamedMutex");             // unnamed mutex

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return -1;
	}
	std::cout << "Aquiring mutex 1" << std::endl;
	WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval
	std::cout << "Aquired mutex 1" << std::endl;
	::Sleep(20000);

    std::cout << "Returnng!\n";
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
