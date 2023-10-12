#include <iostream>
using Rank = unsigned int; // 秩
#define DEFAULT_CAPACITY 3 // 默认的初始容量（实际应用中可设置为更大）

template <typename T>
class Vector
{ 
    // 向量模板类
protected:
    Rank _size;
    Rank _capacity;
    T *_elem;                                    // 规模、容量、数据区
    void copyFrom(T const *A, Rank lo, Rank hi); // 复制数组区间A[lo, hi)
    void expand();                               // 空间不足时扩容
    void shrink();                               // 装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);               // 扫描交换
    void bubbleSort(Rank lo, Rank hi);           // 起泡排序算法
    Rank maxItem(Rank lo, Rank hi);              // 选取最大元素
    void selectionSort(Rank lo, Rank hi);        // 选择排序算法
    void merge(Rank lo, Rank mi, Rank hi);       // 归并算法
    void mergeSort(Rank lo, Rank hi);            // 归并排序算法
    void heapSort(Rank lo, Rank hi);             // 堆排序（稍后结合完全堆讲解）
    Rank partition(Rank lo, Rank hi);            // 轴点构造算法
    void quickSort(Rank lo, Rank hi);            // 快速排序算法
    void shellSort(Rank lo, Rank hi);            // 希尔排序算法
public:
    // 构造函数
    Vector(Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0) // 容量为c、规模为s、所有元素初始为v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }                                                                           // s<=c
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); }                           // 数组整体复制
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }               // 区间
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }               // 向量整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // 区间
    // 析构函数

    ~Vector() { delete[] _elem; } // 释放内部空间

    // 只读访问接口
    Rank size() const { return _size; }                       // 规模
    bool empty() const { return !_size; }                     // 判空
    Rank find(T const &e) const { return find(e, 0, _size); } // 无序向量整体查找
    Rank find(T const &e, Rank lo, Rank hi) const;            // 无序向量区间查找
    Rank search(T const &e) const                             // 有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; // 有序向量区间查找
    // 可写访问接口

    T &operator[](Rank r);                               // 重载下标操作符，可以类似于数组形式引用各元素
    const T &operator[](Rank r) const;                   // 仅限于做右值的重载版本
    Vector<T> &operator=(Vector<T> const &);             // 重载赋值操作符，以便直接克隆向量
    T remove(Rank r);                                    // 删除秩为r的元素
    Rank remove(Rank lo, Rank hi);                       // 删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const &e);                     // 插入元素
    Rank insert(T const &e) { return insert(_size, e); } // 默认作为末元素插入
    void sort(Rank lo, Rank hi);                         // 对[lo, hi)排序
    void sort() { sort(0, _size); }                      // 整体排序
    void unsort(Rank lo, Rank hi);                       // 对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  // 整体置乱
    Rank dedup();                                        // 无序去重
    Rank uniquify();                                     // 有序去重
    // 遍历
    void traverse(void (*)(T &)); // 遍历（使用函数指针，只读或局部性修改）
    template <typename VST>
    void traverse(VST &); // 遍历（使用函数对象，可全局性修改）
};                        // Vector

template <typename T> // T为基本类型，或已重载赋值操作符”=“
void Vector<T>::copyFrom(T *const A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2(hi - lo)]; // 分配内存空间
    _size = 0;                             // 规模清零
    while (lo < hi)
    {                             // A[lo, hi]内的元素逐一
        _elem[_size++] = A[lo++]; // 复制至_elem[0, hi-lo]
    }
}

template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity)
    {
        return 0;
    }
    if (_capacity < DEFAULT_CAPACITY)
    {
        _capacity = DEFAULT_CAPACITY;
    }
    T *oldElem = _elem;
    _elem = new T[_capacity * 2];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = oldElem[i];
    }
}

template <typename T>
void Vector<T>::shrink()     //装填因子过小时压缩向量所占空间
{
    if(_capacity < DEFAULT_CAPACITY << 1) return;   //不致收缩到DEFAULT_CAPACITY以下
    if(_size << 2 < _capacity){
        T *oldElem = _elem;
        _elem = new T[_capacity >>= 1];   //容量减半
        for(int i = 0; i < _size; i++){
            _elem[i] = oldElem[i];   //复制原向量内容
        }
        delete [] oldElem;     //释放原空间
    }
}

template <typename T>
Rank Vector<T>::remove(Rank lo, Rank hi)
{
    if(lo == hi) return 0;
    while(hi<_size){
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink()
    return (hi - lo);
}

template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r,r + 1);
    return e;
}