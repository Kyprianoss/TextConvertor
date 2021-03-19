#include <iostream>
#include <fstream>
#include <bitset>
#include <fstream>
#include <windows.h>
#include <chrono>

using namespace std;

string content;
char yORn;
char options;
string plainText;

void exitconsole() {
    cout<<endl<<"Console will automaticly close in 5 seconds. If you have selected to save the file please do not close the console";
    chrono::steady_clock::time_point tend = chrono::steady_clock::now() //
                                               + chrono::seconds(5);    //
    while (chrono::steady_clock::now() < tend)                          // Give some time to user to read the file path if they have selected yes
    {                                                                   // Closing the console before 5 seconds when selected yes will cause the file to not
        //                                                              // save its data
    }
}

void convertToASCII(string letter)
{
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        cout <<int(x)<<endl;
    }
    cout<<endl<<"Do you want to store this in a text file? [y/n]"<<endl;
    cin>>yORn;
    if (yORn == 'y') {
        ofstream makefile("converted.txt");
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        makefile<<int(x)<<" ";
    }
        char filename[] = "converted.txt";
        char fullFilename[MAX_PATH];
        GetFullPathName(filename, MAX_PATH, fullFilename, nullptr);
        cout<<"Converted.txt file has been created in "<<fullFilename<<endl;
        exitconsole();
    }
    else if (yORn == 'n') {
        cout<<"No selected";
        exitconsole();
    }
    else {
        cout<<options<<" is not an option"<<endl;
        exitconsole();
    }
}


int main()
{   cout<<"TextConvertor"<<"Choose what you want to do:"<<endl<<"Text to binary: b"<<endl<<"Text to ASCII: a"<<endl<<"[b/a]: ";
    cin>>options;
    if (options == 'b') {
    cout<<"Enter text to be converted to binary (placing a space in the text will cause errors):"<<endl;
    cin>>content;
      for (std::size_t i = 0; i <  content.size(); ++i) {
        cout << bitset<8>( content.c_str()[i]) <<endl;
    }
        cout<<endl<<"Do you want to store this in a text file? [y/n]"<<endl;
        cin>>yORn;
        if (yORn == 'y') {
            ofstream makefile("converted.txt");
            for (std::size_t i = 0; i <  content.size(); ++i) {
                makefile << bitset<8>( content.c_str()[i]) <<" ";
            }
            char filename[] = "converted.txt";
            char fullFilename[MAX_PATH];
            GetFullPathName(filename, MAX_PATH, fullFilename, nullptr);
            cout<<"Converted.txt file has been created in "<<fullFilename<<endl;
            exitconsole();
        }
       else if (yORn == 'n') {
            cout<<"No selected";
            exitconsole();
        }
       else {
        cout<<yORn<<" is not y or n";
        exitconsole();
       }
    }
    else if (options == 'a') {
        cout << "Enter text to be converted to ASCII (placing a space in the text will cause errors):"<<endl;
        cin >> plainText;
        convertToASCII(plainText);
        }
    else {
        cout<<options<<" is not an option"<<endl;
    }
    return 0;
}
