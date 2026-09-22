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
    while (ct1 < ct2){
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
struct paire {
    int index;
    int val;
};

bool compareP(const paire &a, const paire &b){
    return a.val < b.val;
}

int TwoSum3(int n[], int s, int size){
    int ct1 = 0;
    int ct2 = size - 1;
    int v = 0;
    paire save[size];
    for (int i = 0; i< size; ++i){
        save[i].index = i;
        save[i].val = n[i]; 
    }
    sort(save, save + size, compareP);
    while (ct1 < ct2){
        int target = s - save[ct1].val;
        if (target == save[ct2].val){
            cout << save[ct1].index << " " << save[ct2].index << '\n';
            ++ct1;
            --ct2;
            ++v;
        }else if (target > save[ct2].val){
            ++ct1;
        }else{
            --ct2;
        }
    }
    return v;
}

int missNum(int a[], int n){
    int t = ((n + 1)* (n))/2;
    for (int i = 0; i < n; ++i){
        t -= a[i];
    }
    return t;
}
struct luu{
    int gt = INT_MIN;
    int bd;
    int kt;
};
luu bien;
int sum1(int p[], int a, int b){
    int t = 0;
    for (int i = a; i <= b; ++i){
        t += p[i];
    }
    return t;
}
int kadane(int a[], int n){
    int t;
    for (int i = 0; i < n; ++i){
        for (int j = n -1; j > i; --j){
            t = sum1(a, i, j);
            if (bien.gt < t){
                bien.bd = i;
                bien.kt = j;
                bien.gt = t;
            }
        }
    }
    cout << bien.bd << " " << bien.kt;
    return bien.gt;
}
int kadane1(int a[], int n){
    int curMax = a[0];
    int gloMax = a[0];
    int tempbd;
    for (int i = 1; i < n; ++i){
        if (a[i] > a[i] + curMax){
            tempbd = i;
            curMax = a[i];
        }else{
            curMax = a[i] + curMax;
        }
        if (gloMax < curMax){
            bien.bd = tempbd;
            bien.kt = i;
            gloMax = curMax;
        }
    }
    cout << bien.bd << " " << bien.kt << '\n';
    return gloMax;
}
int main() {
  int a[] = {-21, -5, -9, -10, 1, 5, 6, 7, -2, -3, -4};
  cout<< kadane1(a, 11);
}