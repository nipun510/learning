#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::vector<std::thread> cont;

std::mutex fun_mutex;

void get_id()
{

	for(auto & t : cont)
	{
		std::cout << t.get_id() << std::endl;

		t.join();
	}
}


void fun()
{
	std::lock_guard<std::mutex> lk(fun_mutex);
	std::cout << "inside fun " << std::endl; 
}
int  main()
{
	std::thread t1{fun};
	std::thread t2{fun};
	std::thread t3{fun};
	std::thread t4{fun};

	std::this_thread::sleep_for(std::chrono::seconds{2});
	std::cout << "getting ids of stored threads " << std::endl;
	
	cont.push_back(std::move(t1));// thread points to system thread so can't be copied.
	cont.push_back(std::move(t2));
	cont.push_back(std::move(t3));
	cont.push_back(std::move(t4));

	get_id();
} 