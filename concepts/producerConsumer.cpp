#include <vector>
#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std::chrono_literals;

/*
Thread safe circular buffer. producer consumer with waiting.
Added by Khushhali
*/




#define ACQUIRE_QUEUE_LOCK std::unique_lock<std::mutex> lk{_mutex};
        

template<typename T>
class circular_buffer {
private:
	void print(const char *fn) {
		std::cout << fn << " :- start [" << _start << "], end ["<< _end << "], size [" << _size << "]" << std::endl;
	}

public:

	circular_buffer(int capacity) : _start{0}, 
									_end{0},
									_size{0},
									_capacity{capacity},
									_buffer(capacity)
									{
									    print(__func__);
									}

	int size() const{
	    ACQUIRE_QUEUE_LOCK;
		return _size;
	}

	void push(T val) {
	    ACQUIRE_QUEUE_LOCK;
	    while (_size == _capacity) {
	        _cv.wait(lk,[&] {return _size < _capacity;});
	    }
		 _size = _size == _capacity ? _capacity : _size + 1;
		_buffer[_end] = val;
		_end = (_end + 1) % _capacity;
		print(__func__);
		_cv.notify_one();
	}

	void pop() {
	    ACQUIRE_QUEUE_LOCK;
	    while (_size == 0) {
	        _cv.wait(lk, [&] { return _size != 0; });
	    }
		_start = (_start + 1) % _capacity;
		--_size;
		print(__func__);
		_cv.notify_one();
	}

	T front() {
	    ACQUIRE_QUEUE_LOCK;
		if (_size == 0) {
			throw std::runtime_error("circular_buffer is empty\n");
		}
		print(__func__);
		return _buffer[_start];
	}
	
private:
	int _start;
	int _end;
	int _size;
	int _capacity;
    std::vector<T> _buffer;
    
    //thread safety
    std::mutex _mutex;
    std::condition_variable _cv;


};


void produce(circular_buffer<int> & circular_buffer) {
	circular_buffer.push(1);
}


void consume(circular_buffer<int> & circular_buffer) {
	circular_buffer.pop();
	circular_buffer.pop();
	circular_buffer.pop();
}

int main() {
	circular_buffer<int> cb(3);

	
	std::thread producer1([&cb](){produce(cb);});


    std::thread consumer([&cb](){consume(cb);});
    std::this_thread::sleep_for(1s);
    cb.push(12);
    cb.push(232);

	producer1.join();

    consumer.join();

}
