#include <map>
#include <iostream>
#include <string>

template<typename Iterator>
bool wasAlreadyInMap(const std::pair<Iterator, bool> &insertionResult){
    return !insertionResult.second;
}

int main(){
   std::map<int, std::string> map{{1, "st1"}, {2, "st2"}};
   auto p = map.insert(std::make_pair(1, "newstr"));
   std::cout << wasAlreadyInMap(p);
  
}
