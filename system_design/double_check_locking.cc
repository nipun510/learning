#include <iostream>
#include <thread>
#include <mutex>
/*
In software engineering, double-checked locking (also known as "double-checked locking optimization"[1]) is a software design pattern
 used to reduce the overhead of acquiring a lock by testing the locking criterion (the "lock hint") before acquiring the lock. 
 Locking occurs only if the locking criterion check indicates that locking is required.
*/

bool globalStatus = false;
std::mutex m_gs;

void setGlobalStatus(){
    std::lock_guard<std::mutex> lock(m_gs);
    globalStatus = true; // this code has to be executed only once, however lock is acquired everytime it is called.
}

void setGlobalStatusImproved(){
    //this is called double checked locking
    if (not globalStatus) {
        std::lock_guard<std::mutex> lock(m_gs);
        if (not globalStatus) {
            globalStatus = true;
        }
    }
}


int main(){
    auto l = [](){setGlobalStatus();};
    std::thread t1(l);
}
