#include "vector.h"

int main(int argc, char const *argv[])
{
    Vector<int> vec {1,2,3,4,5,6,7};
    // vec.push_back(1);
    // vec.push_back(5);
    // vec.push_back(13);
    // vec.push_back(2);
    // vec.push_back(5);
    // vec.push_back(5);
    // vec.push_back(5);
    // vec.push_back(5);
    // vec.push_back(5);

    //std::cout << vec.size() << std::endl;
    //std::cout << vec.copacity() << " ";

    

    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size();
    std::cout << std::endl;

    vec.erase(1, 2);
    
     for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size();
    std::cout << std::endl;
    return 0;
}
