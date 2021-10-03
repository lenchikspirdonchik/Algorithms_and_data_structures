#include <iostream>
#include <valarray>
//y=2x/(1+sin(a+x/2))	0,7   	5,6  	0,5

double myFunction(float x, float a) {
    return 2 * x / (1 + sin(a + x / 2));
}

int main()
{
    int i = 1;
    float x = 0.7, xStop = 5.6, xDelta = 0.5, a = 0.0;
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "\n_________________________________________________";
    std::cout << "\n| No|\tX\t|\ta\t|\t f(x)\t|";
    std::cout << "\n_________________________________________________";
    while (x <= xStop) {
        float func = myFunction(x, a);
        printf("\n|%d  |\t%2.2f\t|\t%2.2f\t|\t%3.3f\t|", i, x, a, func);

        i++;
        x += xDelta;
    }
    std::cout << "\n_________________________________________________";
    return 0;
}