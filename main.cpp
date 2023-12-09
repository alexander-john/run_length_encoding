/*
 * This program was created by Alexander John
 *
 * Run-length encoding
 *
 * Run length encoding is a form of lossless data compression in which runs
 * of data (sequences in which the same data value occurs in many consecutive
 * data elements) are stored as a single data value and count, rather than as
 * the original run.
 *
 * example:
 *
 * given a string:
 * WWWWWWWWWWBWWWWWWBBBBWWWWWEEEEE
 *
 * using run length encoding our encoded string would be:
 * 10W1B6W4B5W5E
 *
 */

#include <iostream>
#include <string>
#include "run-length-enc.h"

int main() {
    std::string str = "wwwwrrrrrrrrrfffffffffffsssssssssss";

    std::cout << str << std::endl;

    std::string encodedStr = runLengthEncode(str);

    std::cout << encodedStr << std::endl;

    std::string decodedStr = runLengthDecode(encodedStr);

    std::cout << decodedStr << std::endl;

    return 0;
}

std::string runLengthEncode(std::string str) {
    std::string encodedString;
    encodedString = "";
    int count = 1;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            encodedString += std::to_string(count) + str[i];
            count = 1;
        }
    }


    return encodedString;
}

std::string runLengthDecode(const std::string& str) {
    std::string decodedString;
    decodedString = "";
    std::string count;
    count = "";

    for (char i: str) {
        if (isdigit(i)) {
            count += i;
        } else {
            int iterate = std::stoi(count);

            for (int j = 0; j < iterate; ++j) {
                decodedString += i;
            }

            count = "";
        }
    }


    return decodedString;
}