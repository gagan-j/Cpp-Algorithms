#include <iostream>
using namespace std;


int main() {
    int a = 20;
    int b = 28;

    while(a != 0 && b != 0){              
        if(a > b){
            a = a % b;                     // for better eff use (%) instead of (-)
        }
        else{
            b = b % a;
        }
    }

    if(a == 0) cout << b;
    else cout << a;
    

    return 0;
}