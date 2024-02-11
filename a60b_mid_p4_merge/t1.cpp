#include <iostream>
#include <vector>

/*
mergesort(a, l, r)
1. 1. ถข้าขข้อมมูลในรายการลลาดจับทรีที่ [l,r) เรรียงลลาดจับไมย่ลดลงอยมูย่แลข้ว (สลาหรจับทรุกๆคย่า i ทรีที่ l<=i<r-1, a[i] <= a[i+1]) ใหข้รรีเททิรร
นทจันทรี (การทลางานสย่วนนรีนี้เปป็นสย่วนทรีที่เพทิที่มขถึนี้นมาจาก merge sort แบบ ปรกตทิ)
2. ใหข้ mid = (l+r)/2
3. เรรียก mergesort(a,l,mid)
4. เรรียก mergesort(a,mid,r)
5. ผสานสย่วนของรายการ [l, mid) และ [mid, r) ทลาใหข้สย่วนของรายการ [l, r) เรรียงในลลาดจับทรีที่ไมย่ลดลง

*/
using namespace std;

// 1 == valid, 0 == invalid
int is_non_dec(vector<int> &v,int right, int left, int prev, int n) {
    if (n == right) return 1;
    if (prev > n) return 0;
    return is_non_dec(v,right, left, v[n], n+1);
}
int is_non_dec(vector<int> &v, int right, int left) {
    if (left == 0) left = 1;
    return is_non_dec(v, v.size(), left, v[left-1], 1);
}

int merge_count(vector<int> &v, int left, int right ) {
    if (left == right) return 1;
    if (is_non_dec(v, left, right) ) return 0;
    int mid = (right+left) >> 1;
    return 1 + merge_count(v, left, mid) + merge_count(v,mid, right);
}
int merge_count(vector<int> &v) {
    return merge_count(v, 0, v.size());
}

int main() {
    vector<int> a = {1,2,3,4};
    vector<int> b = {2,1,3};
    cout << merge_count(a) << endl;
    cout << merge_count(b) << endl;
    return 0;
}