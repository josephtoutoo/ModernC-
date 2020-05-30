// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#include <thread>


void Test1()
{
	std::cout << "T1 started" <<std::endl;
	// Create a mutex with no initial owner

	HANDLE ghMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		L"UnanamedMutex");             // unnamed mutex

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return ;
	}
	WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval
	int count = 1;
	while (count++ < 5)
	{
		std::this_thread::sleep_for(std::chrono::seconds(20));
	}
	::ReleaseMutex(ghMutex);
	std::cout << "Releasinf mutex T1" << std::endl;
	//::ReleaseMutex(ghMutex);
	std::cout << "Terminated" << std::endl;
	/*WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval
	std::cout << "Aquired again 1" << std::endl;
	std::cout << "Terminated" << std::endl;
	WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval
	std::cout << "Aquired again 2" << std::endl;*/
}

void Test2()
{
	std::cout << "T2 started" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(20));
	HANDLE mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"UnanamedMutex");
	if (mutex == NULL)
		std::cout << "T2 Failed to open mutex" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(60));
	::ReleaseMutex(mutex);
	std::cout << "Releasing mutex T2" << std::endl;
	int count = 1;
	while (count++ < 6)
	{
		std::this_thread::sleep_for(std::chrono::seconds(20));
	}
	std::cout << "T2 Terminated" << std::endl;

}
void Test3()
{
	
	std::this_thread::sleep_for(std::chrono::seconds(30));
	HANDLE mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"UnanamedMutex");
	if (mutex == NULL)
		std::cout << "T3 Failed to open mutex" << std::endl;
	std::cout << "T3 started" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(30));
	std::cout << "Aquiring mutex T3" << std::endl;
	WaitForSingleObject(
		mutex,    // handle to mutex
		INFINITE);  // no time-out interval
	std::cout << "Aquired mutex T3" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(60));

	::ReleaseMutex(mutex);
	std::cout << "Released mutex T3" << std::endl;
	int count = 1;
	while (count++ < 6)
	{
		std::this_thread::sleep_for(std::chrono::seconds(20));
	}
	std::cout << "T2 Terminated" << std::endl;

}
int main()
{
	std::thread t1(Test1);
	std::thread t2(Test2);
	std::thread t3(Test3);

	t1.join();
	t2.join();
	t3.join();

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
