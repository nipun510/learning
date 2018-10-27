#include <thread>
#include <iostream>

void fun()
{
	throw(std::runtime_error("Exception")); // this will cause program to terminate
}


int main()
{
	try
	{
		// If a task throws an exception 
		//and doesn’t catch it 'itself' std::terminate() is called
		//A std::future can transmit an exception to the parent/calling thread; 
		//that’s one reason to like futures.
		std::thread t{fun};

		//When a thread 
		//goes out of scope the program is terminate()d unless its task has completed.
		t.join();	
	}
	catch(...)
	{
		std::cout << "exception caught";
	}

}