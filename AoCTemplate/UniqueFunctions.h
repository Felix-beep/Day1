#pragma once
#include "includes.h"

auto removeLetters = [](const string& str) {
	auto filtered = str | std::ranges::views::filter([](char c) { return std::isdigit(c); });
	std::string result;
	std::ranges::copy(filtered, std::back_inserter(result));
	return result;
};

auto firstAndLast = [](const string& str) {
	return string(str.substr(0, 1) + str.substr(str.size() - 1, 1));
};

map<int, string> NumberToWord = {
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
};

auto isSubstring = [](const string& str, const string& sub) {
	return str.compare(0, sub.length(), sub) == 0;
};

auto FindValidNumbers = [](const string& str, vector<int>& PossibleNumbers) {
	auto newPossibleNumbers = PossibleNumbers | std::ranges::views::filter([&str](int num) {
		return isSubstring(NumberToWord[num], str);
		});
	vector<int> result; 
	std::ranges::copy(newPossibleNumbers, std::back_inserter(result));
	return result;
};

auto ProcessString = [](const string& str) {
	vector<int> AvailableNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string newStr;
	int index = 0;
	int curtain = 0;

	for(char c : str) {
		string rest = str.substr(index);
		vector<int> PossibleNumbers = AvailableNumbers;
		string buffer;
		for (char r : rest) {
			buffer += r;
			PossibleNumbers = FindValidNumbers(buffer, PossibleNumbers);
			if (PossibleNumbers.size() == 0) {
				if (index >= curtain) {
					newStr += c;
					curtain++;
				}
				break;
			}
			if (PossibleNumbers.size() == 1) {
				if (NumberToWord[PossibleNumbers[0]] == buffer) {
					newStr += to_string(PossibleNumbers[0]);
					curtain = index + buffer.size();
					break;
				}
			}
		}
		index++;
	}

	cout << newStr << endl;

	return newStr;
};