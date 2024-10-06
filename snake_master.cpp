#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    
    int num=1;
    int i,j;
    for(i=0;i<n;i++){
        if(i%2==0){
            for(j=0;j<n;j++) {
                cout << num++ <<" ";
            }
            cout<<endl;
        }
        else{
            num=num+n-1;
            for(j=0;j<n;j++){
                cout << num-- <<" ";
        }
        cout<<endl;
        num=num+n+1;
    }
   
    
    
}
} 
