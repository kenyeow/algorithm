#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphabet) - 1;

const int numberOfUrls = 100000;

string urls[numberOfUrls];

char genRandomAlphabet()  // Random string generator function.
{
    return alphabet[rand() % stringLength];
}

string generateRandomUrl() { // Random URL generator function
    int randomLength = rand() % 10 + 3;
    string link;
    link.append("www.");
    for (int i = 0; i < randomLength; i++){
        link.push_back(genRandomAlphabet());
    }
    link.append(".com");

    return link;
}

void storeRandomUrl(string url[]) { // Store URLs into an array
    for (int i = 0; i < numberOfUrls; i++){
        url[i] = generateRandomUrl();
    }
}

void printRandomUrls(){
    int number;
    cout << "How many URLs you'd like to print out (max: " << numberOfUrls << ") :";
    cin >> number;
    for (int i = 0; i < number; i++){
        cout << urls[i] << endl;
    }
    cout << endl << endl;
}

void seqSearch(){ // sequential search algorithm
    string inputUrl;
    int foundLocation = -1;
    cout << "Enter the URL you'd like to search: ";
    cin >> inputUrl;
    for (int i = 0; i < numberOfUrls; i++){
        if(urls[i] == inputUrl){
            foundLocation = i;
        }
    }

    if (foundLocation < 0){
        cout << "URL is not found";
        return;
    }

    cout << "The location of the URL is on " << foundLocation << "." << endl;
}

int main()
{
    int selection = -1;
    srand(time(0));
    storeRandomUrl(urls);

    cout << "Select Algorithm: " << endl;
    cout << "1) Sequential Search" << endl;
    cout << "2) Binary Search" << endl;
    cout << "9) Print Random Urls" << endl;
    cout << "0) Exit Program" << endl;
    cout << endl;
    while (selection != 0){
        cout << endl << "Your Selection: ";
        cin >> selection;
        switch(selection){
            case 1:
                seqSearch();
                break;
            case 9:
                printRandomUrls();
                break;
            default:
                cout << "Invalid Selection" << endl;
                break;
        }
    }


    return 0;

}
