#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "current_samples.h"

rangeAndReadings rangeReadings;
int sizeOfcurrentInAmpere;

TEST_CASE("test current set 1") {
int currentInAmpere[]  = {4,5,6};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeReadings = inRangeReading(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeReadings.numberOfReadingsInRange == 3);
REQUIRE(rangeReadings.range[0] == 4);
REQUIRE(rangeReadings.range[1] == 6);
}

TEST_CASE("test current set 2") {
int currentInAmpere[]  = {2,3,1};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeReadings = inRangeReading(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeReadings.numberOfReadingsInRange == 3);
REQUIRE(rangeReadings.range[0] == 1);
REQUIRE(rangeReadings.range[1] == 3);
}

TEST_CASE("test current set 3") {
int currentInAmpere[]  = {8,8,9,10};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeReadings = inRangeReading(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeReadings.numberOfReadingsInRange == 4);
REQUIRE(rangeReadings.range[0] == 8);
REQUIRE(rangeReadings.range[1] == 10);
}

TEST_CASE("test current set 4") {
int currentInAmpere[]  = {24,24,25,25,26,27,26};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeReadings = inRangeReading(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeReadings.numberOfReadingsInRange == 7);
REQUIRE(rangeReadings.range[0] == 24);
REQUIRE(rangeReadings.range[1] == 27);
}

