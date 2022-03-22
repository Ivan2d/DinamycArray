#include <iostream>
#include <stdlib.h>
using namespace std;

class DinamicArrayIntNumber 
{
public:

    int* arr;
    int size;

    DinamicArrayIntNumber() 
    {
        this->size = 10;
        arr = new int[size];
    }


    DinamicArrayIntNumber(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    DinamicArrayIntNumber(int size, int n) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }

    DinamicArrayIntNumber(const DinamicArrayIntNumber& dinamic);

    DinamicArrayIntNumber(DinamicArrayIntNumber&& dinamic) :arr(dinamic.arr), size(dinamic.size)
    {
        dinamic.arr = nullptr;
        dinamic.size = 0;
    }

    ~DinamicArrayIntNumber()
    {
        delete[] arr;
    }

    int& operator[](const int index);

    void newsize(int newSize) 
    {
        int* newArray = new int[newSize];

        if (size >= newSize) 
        {
            for (int i = 0; i < newSize; i++) 
            {
                newArray[i] = arr[i];
            }

            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }

        if (size < newSize) 
        {
            for (int i = 0; i < size; i++) 
            {
                newArray[i] = arr[i];
            }

            for (int k = 0; k < newSize - size; k++) 
            {
                newArray[k + size] = 0;
            }

            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }
    }

    int getSize() {
        return size;
    }

    int getElement(int i) {
        return arr[i];
    }

    DinamicArrayIntNumber& operator=(const  DinamicArrayIntNumber diname) 
    {
        delete[] arr;
        size = diname.size;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = diname.arr[i];
        }
        return *this;
    }

    DinamicArrayIntNumber& operator=(DinamicArrayIntNumber&& dinamic)
    {
        delete[] arr;
        size = dinamic.size;
        arr = dinamic.arr;
        dinamic.arr = nullptr;
        return *this;
    }

    friend bool operator == (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator> (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2);

    friend ostream& operator<<(ostream& out, const DinamicArrayIntNumber& d1);
    friend istream& operator>>(istream& in, DinamicArrayIntNumber& d1);
};

DinamicArrayIntNumber::DinamicArrayIntNumber(const DinamicArrayIntNumber& din) 
{
    size = din.size;
    arr = new int[size];
    for (size_t i = 0; i < din.size; i++) 
    {
        arr[i] = din.arr[i];
    }
}

bool operator== (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2) {
    bool flag = true;
    int size1 = d1.size;
    int size2 = d2.size;
    if (size1 != size2) flag = false;

    for (size_t i = 0; i < size1; i++)
    {
        if (d1.arr[i] != d2.arr[i]) flag = false;
    }
    return flag;
}

bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    bool flag = !(d1 == d2);
    return flag;
}

int& DinamicArrayIntNumber::operator[](const int index) 
{
    return arr[index];
}

bool operator> (const const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    bool flag = true;
    int size1 = d1.size;
    int size2 = d2.size;
    if (size1 <= size2) flag = false;

    for (size_t i = 0; i < size1; i++)
    {
        if (d1.arr[i] <= d2.arr[i]) flag = false;
    }
    return flag;
}

bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    bool flag = true;
    int size1 = d1.size;
    int size2 = d2.size;
    if (size1 < size2) flag = false;

    for (size_t i = 0; i < size1; i++)
    {
        if (d1.arr[i] < d2.arr[i]) flag = false;
    }
    return flag;
}

bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    bool flag = true;
    int size1 = d1.size;
    int size2 = d2.size;
    if (size1 >= size2) flag = false;

    for (size_t i = 0; i < size1; i++)
    {
        if (d1.arr[i] >= d2.arr[i]) flag = false;
    }
    return flag;
}

bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    bool flag = true;
    int size1 = d1.size;
    int size2 = d2.size;
    if (size1 > size2) flag = false;

    for (size_t i = 0; i < size1; i++)
    {
        if (d1.arr[i] > d2.arr[i]) flag = false;
    }
    return flag;
}

DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2) 
{

    DinamicArrayIntNumber result = DinamicArrayIntNumber(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++) 
    {
        result.arr[i] = d1[i];
    }

    for (int i = d1.size; i < (d1.size + d2.size); i++) {
        result.arr[i] = d2[i];
    }
    return result;
}


ostream& operator<< (ostream& out, const DinamicArrayIntNumber& dinamic)
{

    out << "DinamicArrayIntNumber(";
    for (int i = 0; i < dinamic.size; i++) {
        out << dinamic.arr[i] << ", ";
    }
    out << ")";

    return out;
}

istream& operator>> (istream& in, DinamicArrayIntNumber& dinamic)
{

    for (int i = 0; i < dinamic.size; i++) {
        in >> dinamic.arr[i];
    }

    return in;
}

int main()
{
    DinamicArrayIntNumber di1(10, 5);
    DinamicArrayIntNumber di2(di1);

    for (int i = 0; i < di2.size; i++) {
        cout << di2.getElement(i) << "\t";
    }
    cout << endl;

    di2.newsize(4);

    for (int i = 0; i < di2.size; i++) {
        cout << di2.getElement(i) << "\t";
    }
}
