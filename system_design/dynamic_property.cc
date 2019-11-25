#include <iostream>
#include <map>

class valueType{
    public:
    virtual valueType * clone() const
    {
        return new valueType();
    }
    virtual std::string get() const
    {
        return "value";
    }
};

class value1 : public valueType{
    public:
    virtual std::string get() const override
    { 
        return "value1";
    }
    virtual value1* clone() const override{
        return new value1();
    }
};
class value2 : public valueType{
    public:
    virtual std::string get() const override
    { 
        return "value2";
    }
    virtual value2* clone() const override
    {
        return new value2();
    }
};

//fixed property
class A
{
public:
    valueType getName();
    valueType getAddress();
private:
    valueType name;
    valueType address;
    
};

//flexible dynamic property
class B
{
public:
    valueType getValue(std::string key){
        return values[key]; 
    }
    void setValue(std::string key, valueType value){
        values[key] = value;
    }
private:
    std::map<std::string, valueType> values;
};

//defined dynamic propery
class propertyType
{
private:
    static std::map<std::string, propertyType> _properties;
    std::string _name;
public:
    static propertyType getProperty(const std::string & name) 
    {
        if (_properties.find(name) == _properties.end()){ throw std::logic_error("bad property Name");};
        return _properties[name];
    }
    static hasProperty(const std::string & name)
    {
        return _properties.find(name) != _properties.end();
    }
    propertyType () {};
    propertyType(std::string name){
        _name = name;
        _properties.insert({_name, *this});
    }
    propertyType(const propertyType & rhs){
        _name = rhs.getName();
    }
    std::string getName() const { return _name; }

};
std::map<std::string, propertyType> propertyType::_properties;

class C
{
public:
    valueType *
    getValue(propertyType key) {
        return values[key.getName()];
    }
    void setValue(propertyType key, valueType* value) {
        valueType *newvalue = value->clone();
        values[key.getName()] = newvalue;
    }
private:
    std::map<std::string, valueType*> values;
};


// Driver code 
int main() 
{
    //flexible dynamic property
    B b;
    value1 val1;
    value2 val2;
    b.setValue("name", val1);
    b.setValue("address", val2);
    
    // defined dynamic propery
    propertyType p1("name");
    propertyType p2("address");
    
    C c;
    
    c.setValue(propertyType::getProperty("name"), &val1);
    c.setValue(propertyType::getProperty("address"), &val2);
    valueType *valc1 = c.getValue(propertyType::getProperty("name"));
    std::cout << valc1->get() << "\n";

    valueType *valc2 = c.getValue(propertyType::getProperty("address"));
    std::cout << valc2->get() << "\n";
    
} 
