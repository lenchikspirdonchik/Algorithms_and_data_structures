#include "iostream"
#include <locale>
using namespace std;


int main(){
    ::setlocale( LC_ALL , "russian_russia.866" );
    cout << "Hello, мой мир!" <<endl;
    cout <<"Hello, мой мир!" << endl;
    printf("\"Hello, мой мир!");
    return 0;
}