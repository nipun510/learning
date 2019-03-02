#include <iostream>

class cb
{
    private:
    
    public:
    int reference_count;
    cb(int cnt):reference_count{cnt}
    {}
};

template<typename T>
class shared
{
    private:
    T * obj_ptr;
    cb * cb_ptr;
    public:
   
    template<typename ...Args>
    shared(Args ...args)
    {
        cb_ptr = new cb(1);
        obj_ptr = new T(args...);
    }
    
    shared(const shared & rhs)
    {
        this->obj_ptr = rhs.obj_ptr;
        this->cb_ptr = rhs.cb_ptr;
        this->cb_ptr->reference_count += 1;
    }
    ~shared()
    {
        this->cb_ptr->reference_count -= 1;
        if(this->cb_ptr->reference_count == 0)
        {
            delete obj_ptr;
            delete cb_ptr;
        }
    }
    
    unsigned get_count()
    {
        return cb_ptr->reference_count;
    }
};

int main()
{
    shared<cb> s_ptr(12);
    std::cout << s_ptr.get_count() << "\n";
    shared<cb> s_ptr2 = s_ptr;
    std::cout << s_ptr2.get_count() << "\n";
    std::cout << s_ptr.get_count() << "\n";
    
}
