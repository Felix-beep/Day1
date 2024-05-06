#include "Includes.h"
#include "HelperFunctions.h"    
#include "UniqueFunctions.h"

using namespace std;

int main()
{
    string Input = readFromFile();

    if (Input == "") return 1;

    // split into lines
    auto Lines = split(Input, '\n');
    for_each_collection(Lines, [](string s) {cout << "[" << s << "]" << endl; });

	// split into numbers
    cout << endl;


    auto result = Lines 
        | std::ranges::views::transform([](const string& str) 
            {
                return processString(str);
            })
        | std::ranges::views::transform([](const string& str) 
            {
                return removeLetters(str);
            }) 
        | std::ranges::views::transform([](const string& str)
            {
                return firstAndLast(str);
            });


    
    auto solution = accumulate_collection(result, 0, [](int sum, string inp) {
        return sum + stoi(inp);
        });

    cout << solution << endl;
    
    return 0;
}
