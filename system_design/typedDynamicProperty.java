import java.util.*;

/*
Typed Dynamic Property
Type checking is being done at runTime and not at Design runTime
Type checing of property as well as its value is being done
*/
class PropertyType {
    PropertyType(String name, Class value) {
        
        _properties.put(name, this);
        _name = name;
        _valueType = value;
    }
    public static PropertyType getProperty(String name) throws Exception{
        if (! _properties.containsKey(name)) {
            throw new Exception("key not found");
        }
        return _properties.get(name);
    }
    public Class getValueType() {
        return _valueType;
    }
    public String getName() {
        return _name;
    }
    private static HashMap<String, PropertyType> _properties =  new HashMap<String, PropertyType>();
    private Class _valueType;
    private String _name;
}

class A 
{
    void setValue(PropertyType key, Object value) throws Exception
    {
        if (! key.getValueType().isInstance(value)) {
          throw new Exception("value not valid");
        }
        
        _values = new HashMap<PropertyType, Object>();
        _values.put(key, value);
    }
    
    Object getValue(PropertyType key)
    {
        return _values.get(key);
    }
    private HashMap<PropertyType, Object> _values;
}

public class Main
{
	public static void main(String[] args) throws Exception{
	    
	    PropertyType p1 = new PropertyType("age", Class.forName("java.lang.Integer"));
	    PropertyType p2 = new PropertyType("address", Class.forName("java.lang.String"));
	    
		A a = new A();
		a.setValue(PropertyType.getProperty("age"), 21);
		System.out.println(a.getValue(PropertyType.getProperty("age")));
		a.setValue(PropertyType.getProperty("address"), "kolkata");
		System.out.println(a.getValue(PropertyType.getProperty("address")));
	}
}
