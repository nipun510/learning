"""
Difference between Generator function and Normal function –

    Once the function yields, the function is paused and the control is transferred to the caller.
    When the function terminates, StopIteration is raised automatically on further calls.
    Local variables and their states are remembered between successive calls.
    Generator function contains one or more yield statement instead of return statement.
    As the methods like _next_() and _iter_() are implemented automatically, we can iterate through the items using next().
"""

def generator(): 
    t = 1
    print('First result is ',t )
    yield t 
  
    t += 1
    print('Second result is ',t )
    yield t 
  
    t += 1
    print('Third result is ',t )
    yield t 
  
call = generator() 
next(call) 
next(call) 
next(call) 