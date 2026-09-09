#include <bits/stdc++.h>

using namespace std;



int max(int n[], int size){
    int t = 0;
    for (int i = 0; i < size ; ++i){
        if (n[i] > t){
            t = n[i];
        }
    }
    return t;
}
int TwoSum1(int n[], int s, int size){
    int v = 0;
    for (int i = 0; i< size; ++i){
        for (int j = i + 1; j < size; ++j){
            if (n[j] + n[i]== s){
                ++v;
                cout << n[i] << " " << n[j] <<'\n';
            }
        }
    }
    return v;
}
int TwoSum2(int n[], int s, int size){
    int v = 0;
    sort(n, n + size);
    int ct1 = 0;
    int ct2 = size - 1;
    while (ct1 != ct2){ // xem lai dieu kien nay
        int target = s - n[ct1];
        if (target == n[ct2]){
            cout << n[ct1] << " " << n[ct2] << '\n';
            ++ct1;
            --ct2;
            ++v;
        }else if (target > n[ct2]){
            ++ct1;
        }else{
            --ct2;
        }
    }
    return v;
}

struct pairr {
    int index;
    int val;
};
bool compareP(const pairr &a, const pairr &b){
    return a.val < b.val;
}

int TwoSum3(int n[], int s, int size){
    int v = 0;

    pairr save[size];
    for (int i = 0; i < size; i++){
        save[i].index = i;
        save[i].val = n[i]; 
    }


    sort(save, save+size, compareP);

    int ct1 = 0;
    int ct2 = size - 1;

    while (ct1 < ct2){
        int target = s - save[ct1].val;
        if (target == save[ct2].val){
            
           cout << save[ct1].index << " " << save[ct2].index << '\n'; 
            
            ct1++;
            ct2--;
            v++;

        } else if (save[ct2].val > target ){
            ct2--;
            
        }
        else ct1++;

    }

    return v;
}



int main() {
    int size = 100000;
    int s = 100000; // Giá trị tổng cần tìm (có thể thay đổi tùy ý)

    // Khởi tạo mảng động 1000 phần tử để tránh tràn bộ nhớ stack
    int* n = new int[size];

    // Gán dữ liệu mẫu cho mảng (ví dụ: các số từ 0 đến 999)
    for (int i = 0; i < size; ++i) {
        n[i] = i;
    }

    // Gọi hàm TwoSum
    int result = TwoSum3(n, s, size);

    cout << "So cap thoa man: " << result << endl;

    // Giải phóng bộ nhớ
    delete[] n;

    return 0;
}