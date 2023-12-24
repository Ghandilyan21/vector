#include "vector.h"
int main(int argc, char const *argv[])
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(34);
    vec.push_back(67);
    vec.push_back(12);
    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i] << " ";
    // }
    // vec.insert(2, 10);
    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i] << " ";
    // }
    Vector<int> vec1;
    vec1 = vec;
    Vector<int> vec2 = vec1;
    // for (size_t i = 0; i < vec1.size(); i++)
    // {
    //     std::cout << vec1[i] << " ";
    // }
    return 0;
}
