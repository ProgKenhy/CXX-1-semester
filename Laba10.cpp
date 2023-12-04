#include <iostream>
#include <vector>
using namespace std;
/*
1) resize   - Определяет новый размер вектора. 
              При каждом расширении вектора выделяется новый участок памяти и все элементы перемещаются на него.
2) capacity - Возвращает число элементов, которое вектор может содержать без выделения дополнительного пространства.
   size	    - Возвращает количество элементов в векторе.
   shrink_to_fit	Удаляет лишнюю емкость.
   resize	Определяет новый размер вектора.
   reserve	Резервирует минимальную длину хранилища для объекта вектора.
3) В угловых скобках указывается тип, объекты которого будут храниться в векторе.





*/
int main()
{
    vector <int> v1;

    v1.push_back(1);
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Current capacity of v1 = "
        << v1.capacity() << endl;
    cout << "Current size of v1 = "
        << v1.size() << endl;
    
    v1.erase(v1.begin());
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;
    int myarray[] = { 25,26,27,28 };
    v1.insert(v1.begin() + 2, myarray, myarray+3);
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;
    v1.insert(v1.begin() + 5, 4, 50);
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Current size of v1 = "
        << v1.size() << endl;
    v1.resize(30);
    cout << "Current size of v1 = "
        << v1.size() << endl;
    v1.reserve(100);
    cout << "Current capacity of v1 = "
        << v1.capacity() << endl;
    v1.shrink_to_fit();
    cout << "Current capacity of v1 = "
        << v1.capacity() << endl;
    v1.clear();
    cout << "The size of v1 after clearing is " << v1.size() << endl;
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    //numbers[50] = 9;
    //numbers.at(50) = 9;
    for (auto& v : v1) {
        cout << v << " ";
    }







	return 0;
}