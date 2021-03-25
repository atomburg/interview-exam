/**
* 找出一个正整数，满足条件：
× 1，不在参数数组中，
× 2，最小的一个。
*/
int find_absent_and_minimum(int a [], int n){
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

