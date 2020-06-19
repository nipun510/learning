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

// fixed property 
// all the properties can only be added statically and 
// not dynamically at run time. In below example class A has two fixed
// properties name and adress.
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
// Any property can be added at run time. so no check on property name.
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
// Only pre


class C
{
private:
    class property {
    private:
        std::string _name;
    public:

        property () {};
        property(std::string name){
            _name = name;  
        }
        property(const property & rhs){
            _name = rhs.getName();
        }
        std::string getName() const { return _name; }
    };
    
    static void
    setProperties(std::vector<std::string> validPropertyNames) {
       for (auto & name : validPropertyNames) {
           _properties[name] = new property{name};
       }
    }
    
    
public:
    static bool
    hasProperty(const std::string & name) {
        return _properties.find(name) != _properties.end();
    }
public:
    C (std::vector<std::string> propertyNames) {
        setProperties(propertyNames);
    }
    
    valueType *
    getValue(const std::string &propertyName) {
        if (hasPropery(propertyName)) {
            return _keyValueMap[_properties[propertyName]];
        }
        return nullptr;
    }
    
    bool 
    setValue(const std::string &propertyName, valueType* value) {
        if (value == nullptr || hasProperty(propertyName)) {
            return false;
        }
        valueType *newValue = value->clone();
        _keyValueMap[_properties[propertyName]] = newValue;
        return true;
    }
private:
    std::map<property*, valueType*> _keyValueMap;
    static std::map<std::string, property*> _properties;
};


std::map<std::string, propertyType> C::_properties;

// Driver code 
int main() 
{
    //flexible dynamic property, no check on propertyNames
    // here it might be the case that user doesn't want garbage propery in class B.
    B b;
    value1 nameValue;
    value2 addressValue;
    value3 garbageValue;
    b.setValue("name", nameValue);
    b.setValue("address", addressValue);
    b.setValue("garbage", garbageValue);
    
    // defined dynamic propery
    // Only valid property names are allowed.
    std::vector<std::string> propertyNames{"name", "address", "age"};
    C cobj{propertyNames}; // property names for class C fixed now.
    cobj.setValue("name", nameValue);
    cobj.setValue("address", addressValue);
    cobj.setValue("garbage", garbageValue); // this will fail at run time. will return false.
    #ToDo property name check at compile time.
} 
