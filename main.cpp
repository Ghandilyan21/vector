#include "vector.h"

int main(int argc, char const *argv[])
{
    Vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    //vec.push_back(7);

    //std::cout << vec.size() << std::endl;
    //std::cout << vec.copacity() << " ";

    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size();
    std::cout << std::endl;
    //vec.insert(vec.begin() + 3, 9);
    //vec.erase(vec.begin() , vec.begin() + 5);
    vec.assign(5,2);
     for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size();
    std::cout << std::endl;
    return 0;
}
