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

auto FindValidNumbers = [](const string& str) {
	return std::ranges::views::filter([&str](int num) {
		return isSubstring(NumberToWord[num], str);
	});
};

auto processString = [](const string& str) {
	const auto AvailableNumbers = std::ranges::iota_view(1, 10);
	string newStr;
	int index = 0;
	int curtain = 0;

	for(char i : str) {
		string remainingStr = str.substr(index);
		auto PossibleNumbers = AvailableNumbers;
		string word;
		for (char c : remainingStr) {
			word += c;
			PossibleNumbers = PossibleNumbers | FindValidNumbers(word);
			if (PossibleNumbers.size() == 0) {
				if (index >= curtain) {
					newStr += c;
					curtain++;
				}
				break;
			}
			if (PossibleNumbers.size() == 1) {
				if (NumberToWord[PossibleNumbers[0]] == word) {
					newStr += to_string(PossibleNumbers[0]);
					curtain = index + word.size();
					break;
				}
			}
		}
		index++;
	}

	cout << newStr << endl;

	return newStr;
};