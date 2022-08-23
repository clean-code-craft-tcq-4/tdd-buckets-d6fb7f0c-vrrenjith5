#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "current_samples.h"

int sizeOfcurrentInAmpere;
vector<string> rangeOfReadings;

TEST_CASE("test current set 1") {
unsigned int currentInAmpere[]  = {2,3,1};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[1 - 3] , 3");
}

TEST_CASE("test current set 2") {
unsigned int currentInAmpere[]  = {8,8,9,10};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[8 - 10] , 4");
}

TEST_CASE("test current set 3") {
unsigned int currentInAmpere[]  = {24,24,25,25,26,27,26};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[24 - 27] , 7");
}

TEST_CASE("test current set 4") {
unsigned int currentInAmpere[]  = {4,5};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4 - 5] , 2");
}

TEST_CASE("test current set 5") {
unsigned int currentInAmpere[]  = {4,4,4};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4 - 4] , 3");
}

TEST_CASE("test current set 6") {
unsigned int currentInAmpere[]  = {4, 10, 15};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4] , 1");
REQUIRE(rangeOfReadings[1] == "[10] , 1");
REQUIRE(rangeOfReadings[2] == "[15] , 1");
}

TEST_CASE("test current set 7") {
unsigned int currentInAmpere[]  = {11, 11, 10, 12, 46, 44, 47, 44, 45, 45, 43, 3, 3, 5, 4};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[3 - 5] , 4");
REQUIRE(rangeOfReadings[1] == "[10 - 12] , 4");
REQUIRE(rangeOfReadings[2] == "[43 - 47] , 7");
}

TEST_CASE("test current set 8") {
unsigned int currentInAmpere[]  = {};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
bool rangeListStatus = rangeOfReadings.empty();
REQUIRE(rangeListStatus == true);
}
