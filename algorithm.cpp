/**
* 找出一个正整数，满足条件：
× 1，不在参数数组中，
× 2，最小的一个。
*/
int find_absent_min(int a [], int n){
    if (a[0] > 1) return 1;
    for (int i = 0; i < n -1; i++){
        if (a[i] + 1 != a[i+1]) {
            return a[i]+1;
        }
    }
    return a[n-1] + 1;
}
// int a [] = {1,2,3,4}; 
// int a [] = {2,3,4}; 
// int a [] = {3,4}; 
// int a [] = {3,4, 6,7}; 
// find_absent_min(a, sizeof(a)/sizeof(*a));


// 编译时计算阶乘-1
// -std=c++11 or /std:c++11
constexpr int factorial(int n) {return (n==1?1:n*(n-1));}
// int array [factorial(3)] = {0,1,2,3,4,5};

// 编译时计算阶乘-2
// -std=c++11 or /std:c++11
template <int N> struct fact{
    enum {value = N * fact<N-1>::value};
};
// 部分特化
template <> struct fact<1>{
    enum {value = 1};
};
int numbers[fact<5>];// = {0, ..., 119};


// vector的使用
// reserve(n) or shrink_to_fit() is operating capacity(), check vetcor::capacity().
// resize(), erase(), push_back() is operation storage, check vector::size().

// heap的构造
#include <stdio.h>
#include <string.h>

#define parent(i) (i/2)
#define left(i)   (2*i)
#define right(i)  (2*i+1)
#define isroot(i) (i==0)

// 上浮
void adjust(int * h, int tail){
    while(!isroot(tail)) {
        if (h[tail] > h [ parent(tail)]){
            int tmp = h[tail];
            h[tail] = h [ parent(tail)];
            h [parent(tail)] = tmp;
        }
        tail = parent(tail);
    } 
}

// 下沉操作
void sink(int * h, int tail){
    int i = 0;
    while(left(i)<=tail){
        if (right(i) <= tail && h[right(i)]<h[left(i)] && h[right(i)]<h[i]) {
           swap(h[right(i)], h[i]);
           i = right(i);
        }else if (h[left(i)]<h[i]){
           swap(h[left(i)],h[i]);
           i = left(i);
        }else break;
    }
}

int main(int argc, char * argv[])
{
    int num [10] = {110,112,101,102,105,118,120, 111, 115, 114};

    int heap[sizeof(num)];
    
    int tail = 0;
    memset(heap, 0, sizeof(heap)); 

    for(int i = 0; i < 10; i++){
        heap[tail++] = num[i];
        adjust(heap, tail-1);   
    } 
    for(int i = 0; i < 10; i++) printf("%d,", heap[i]); puts("\n");
    // topK选取测试。
    for (int i = 200; i < 300; i++){
        if (heap[0] < i){ 
            heap[0] = i;
            sink(heap, tail-1);
        }
    }
    for(int i = 0; i < 10; i++) printf("%d,", heap[i]); puts("\n");
    fflush(0);
    return 0;
}

// 数一下整数中有几个1
// 因为n&=n-1总是清除最右侧的bit=1的位
int count = 0; while(true){
    n &= n-1; count++;
};
