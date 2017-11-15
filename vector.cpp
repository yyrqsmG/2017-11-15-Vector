/*写一个vector顺序容器。
要求实现：
size()
capacity()
push_back()
front()
back()
data()
*/
#include <iostream>
using namespace std;

template <typename T>
class Vector{
private:
    T *str;
    int m_size;//容器当前拥有的元素个数
    int m_capacity;//容器的容量
public:
    Vector(int size=0, int l=2):m_size(size), m_capacity(l)
    {
        str = new T[m_capacity];
    }
    ~Vector()
    {
        delete[] str;
    }
    
    //重载[]
    T& operator[](int index)
    {
        return *(str+index);
    }
    
    //改变当前vecotr所分配空间的大小
    void reserve(int capacity)
    {
        if(capacity < m_capacity)
            return;
        T* m_str = str;
        m_str = new T[capacity];
        m_capacity = capacity;
        for(int i=0; i<m_capacity; i++)
            str[i] = m_str[i];
        delete[] str;
    }

    //容器当前拥有的元素个数
    int size()
    {
        return m_size;
    }
    //容器的容量
    int capacity()
    {
        return m_capacity;
    }
    //在数组的最后添加一个数据
    void push_back(T t)
    {
        if(m_size==m_capacity)
            reserve(m_capacity*2);
        str[m_size++] = t;
    }
    //得到数组头
    T front()
    {
        return str[0];
    }
    T back()
    {
        return str[m_size];
    }
    //最后一位的地址
    int* data(void)
    {
        return &str[m_size-1];
    }
    //遍历输出
    void show()
    {
        for(int i=0; i<m_size-1; i++)
            cout<<str[i]<<' ';
        cout<<endl;
    }
};

int main(void)
{
    Vector<int> v;
    v.push_back(12);
    v.push_back(23);
    v.push_back(34);
    v.push_back(45);
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.show()<<endl;
}
