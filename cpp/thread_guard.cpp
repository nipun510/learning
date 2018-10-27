#include <iostream>
#include <thread>
#include <functional>


struct guarded_thread : std::thread
{
	using thread::thread; 
	std::thread t;
public:
	guarded_thread(std::function<void(int)> fun)
	{
		t{fun()};
	}
	~guarded_thread()
	{
		if(t.joinable())
		{
			t.join();
		}
	}
};

int main()
{
	std::thread t{12};
}