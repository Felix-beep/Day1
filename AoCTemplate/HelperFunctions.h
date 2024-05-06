#pragma once

#include "includes.h"

string readFromFile(string filename = "Input.txt") {
    ifstream inputFile(filename); // Open the file

    if (!inputFile.is_open()) { // Check if the file opening failed
        std::cerr << "Error: Unable to open the file." << std::endl;
        return string();
    }

    string line;
    stringstream ss;

    while (std::getline(inputFile, line)) { // Read each line from the file
        ss << line << '\n'; // Append each line to stringstream
    }

    if (ss.str().size() == 0) { // Check if the file opening failed
        std::cerr << "Error: file is empty." << std::endl;
        return string();
    }

    std::string fileContent = ss.str(); // Convert stringstream to string

    if (fileContent[fileContent.size() - 1] == '\n') // Remove the last newline character
        fileContent = fileContent.substr(0, fileContent.size() - 1);

    std::cout << "Content read from file:\n[" << fileContent << "]" << endl << endl;

    inputFile.close(); // Close the file
    return fileContent;
}

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    string temp = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == delimiter)
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += input[i];
        }
    }
    result.push_back(temp);
    return result;
}

vector<char> splitToChar(string input)
{
    vector<char> result;
    for (int i = 0; i < input.size(); i++)
    {
        result.push_back(input[i]);
    }
    return result;
}

auto for_each_collection = [](auto collection, auto function)
    {
        return for_each(collection.begin(), collection.end(), function);
    };

auto accumulate_collection = [](auto collection, auto initial, auto function)
    {
        return accumulate(collection.begin(), collection.end(), initial, function);
    };
