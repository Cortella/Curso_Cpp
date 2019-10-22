//Funcao recursiva 1

#include <iostream>
#include <stdlib.h>

using namespace std;

escrevaVertical(int n){
    if(n<10){
        cout<<n<<endl;
    }else{
        escrevaVertical(n/10);
        cout<<(n%10) <<endl;
    }
}
int main(){
    escrevaVertical(235626410);
    system("pause");
    return 0;
}