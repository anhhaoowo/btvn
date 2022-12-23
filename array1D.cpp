#include <iostream>
#include <cmath>

#define FOR(a,b,c) for (int a=b; a<c; a++)
#define PRINT(a,i) printf("a[%d] = %d\n",i,a[i])

using namespace std;

void enterArr(int* a, int &n){
    printf("Enter n: ");
    scanf("%d",&n);
    FOR(i,0,n){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void printArr(int* a, int n){
    FOR(i,0,n)
        PRINT(a,i);
}

bool isPrime(int x){
    if (x<2) return 0;
    if (x<4) return 1;
    FOR(i,2,sqrt(x)+1){
        if (x%i==0) return 0;
    }
    return 1;
}

bool isPalindrome(int *a, int n){
    FOR(i,0,n/2)
        if (a[i]!=a[n-i-1]) return 0;
    return 1;
}

void inputNCheck(int &x, string s, bool cond){
    if (cond) return;
    cout<<s;
    cin>>x;
    inputNCheck(x,s,(x>=-1&&x<=5));
}
void inputNCheck(char &ch, bool &re, string s, bool cond){
    if (cond) return;
    cout<<s;
    cin>>ch;
    re=ch=='Y'||ch=='y';
    inputNCheck(ch,re,s,(ch=='Y'||ch=='y'||ch=='N'||ch=='n'));
}

void bai1(int a[], int n){
    int d=0;
    FOR(i,0,n){
        if (isPrime(a[i])){
            PRINT(a,i);
            d++;
        }
    }
    printf("There is (are) %d prime number(s) in the array\n",d);
}

void bai2(int *a, int n){
    printf("Array is %sPalindrome\n",(isPalindrome(a,n)? "": "not "));
}

void bai3(int *a, int &n){
    int k;
    printf("Enter k: ");
    scanf("%d",&k);
    if (k<0||k>=n){
        printf("0\n");
        return;
    }
    printf("1\nArray which deleted a[%d] = %d:\n",k,a[k]);
    FOR(i,k,n)
        a[k]=a[++k];
    printArr(a,--n);
}

void bai4(int *a, int n){
    int max=*a, d=1;
    FOR(i,1,n)
        max=a[i]>max? a[i]: max;
    printf("Max element: %d\nIndex: ",max);
    FOR (i,0,n)
        if (a[i]==max) printf("%d ",i);
    printf("\n");
}

void bai5(int *a, int n){
    int max=0, d=-1;
    FOR(i,1,n)
        if (a[i]<0)
            if (d==-1||-a[i]<max){
                max=a[i];
                d=i;
            }
    if (d==-1) printf("No negative element found");
    if (d>=0) printf("Max negative element: %d\nIndex: ",max);
    FOR (i,0,n)
        if (a[i]==max&&a[i]<0) printf("%d ",i);
    printf("\n");
}

int main(){
    int n, a[50];
    bool repeat;
    enterArr(a,n);
    do{
        int f;
        char ch;
        bool reEnter;
        inputNCheck(ch,reEnter,"\nDo you want to re-enter array? (Press [Y]-Yes, [N]-No): ",0);
        if (reEnter) enterArr(a,n);
        inputNCheck(f,"Choose function you want to run: [1->5] (Press [0] to exit, [-1] to print array): ",0);
        switch (f){
            case 1:
                bai1(a,n);
                break;
            case 2:
                bai2(a,n);
                break;
            case 3:
                bai3(a,n);
                break;
            case 4:
                bai4(a,n);
                break;
            case 5:
                bai5(a,n);
                break;
            case -1:
                printArr(a,n);
                break;
            case 0:
                return 0;
                break;
        }
        inputNCheck(ch,repeat,"Do you want to do it again? (Press [Y]-Yes, [N]-No): ",0);        
    } while(repeat);
    return 0;
}