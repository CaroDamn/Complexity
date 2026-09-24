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
int maje(int a[], int n){
    unordered_map <int, int> t;
    for (int i = 0; i < n; ++i){
        if (t.find(a[i]) == t.end()){
            t[a[i]] = 1;
        }else{
            ++t[a[i]];
        }
    }
    for (pair<int, int> b: t){
        if (b.second >= n / 2){
            return b.first;
        }
    }
    return -1;
}
int maje1(int a[], int n){
    int candi = 0;
    int count = 0;
    for (int i = 0; i < n; ++i){
        if (count == 0){
            candi = a[i];
            count = 1;
        }else if (candi != a[i]){
            --count;
        }else{
            ++count;
        }
    }
    return candi;
}
int MinK(int a[], int n, int k){
    unordered_map<int, int> t;
    unordered_map<int, int> m;
    int count = 0;
    for(int i = 0; i < n; ++i){
        t[a[i]] = i;
        if (m.find(a[i]) == m.end()){
            m[a[i]] = 1;
        }else{
            ++m[a[i]];
        }
    }
    for (pair <int, int> it : m){
        cout << it.first << " " << it.second << endl;
    }
    
    for (int i = 0; i < n; ++i){
        if (m.find(abs(k - a[i])) != m.end() && i != t[abs(k - a[i])]  ){
            cout << m[a[i]] * m[k - a[i]] << endl;
            count += m[a[i]] * m[k - a[i]];
        }
    return count;
}
}
int main() {
  int a[] = {1,1,3,4,5,3};
  cout<< MinK(a, 6, 2);
}