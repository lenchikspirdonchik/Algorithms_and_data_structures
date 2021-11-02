#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    ofstream MyFile("fileText.txt");
    string addText = "";
    cout << "Напишите текст для добавления его в текстовый файл \n";
    std::getline(std::cin, addText);
    if (addText.length() < 1000)
        MyFile << addText;
    else cout << "Слишком длинная строка \n";
    MyFile.close();

    cout << "_____________________________________________ \n";

    ifstream MyReadFile("fileText.txt");
    char myText[1000];
    MyReadFile.getline(myText, 1000);
    MyReadFile.close();
    cout << "Вывод строки с добавлением пробелов \n";
        for (int i = 0; i < strlen(myText); i++)
        {
            char buff = myText[i];
            if (buff != ' ') cout << buff << " ";
            else cout << buff;
        }

    return 0;
}
