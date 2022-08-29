#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "detect_current_range.h"
#include "high_fidelity_current_sensor.h"
#include "charging_discharging_current_sensor.h"

vector<string> rangeOfReadings;
uint32_t sizeOfcurrentInAmpere;
uint32_t sizeOfcurrentSensor;
vector<uint32_t> actual12BitCurrentValueInAmpere;
vector<int32_t> actual10BitCurrentValueInAmpere;

/*Start: Test Current Ranges*/

TEST_CASE("test current set 1") {
uint32_t currentInAmpere[]  = {2,3,1};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[1 - 3] , 3");
}

TEST_CASE("test current set 2") {
uint32_t currentInAmpere[]  = {8,8,9,10};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[8 - 10] , 4");
}

TEST_CASE("test current set 3") {
uint32_t currentInAmpere[]  = {24,24,25,25,26,27,26};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[24 - 27] , 7");
}

TEST_CASE("test current set 4") {
uint32_t currentInAmpere[]  = {4,5};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4 - 5] , 2");
}

TEST_CASE("test current set 5") {
uint32_t currentInAmpere[]  = {4,4,4};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4 - 4] , 3");
}

TEST_CASE("test current set 6") {
uint32_t currentInAmpere[]  = {4, 10, 15};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[4] , 1");
REQUIRE(rangeOfReadings[1] == "[10] , 1");
REQUIRE(rangeOfReadings[2] == "[15] , 1");
}

TEST_CASE("test current set 7") {
uint32_t currentInAmpere[]  = {11, 11, 10, 12, 46, 44, 47, 44, 45, 45, 43, 3, 3, 5, 4};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
REQUIRE(rangeOfReadings[0] == "[3 - 5] , 4");
REQUIRE(rangeOfReadings[1] == "[10 - 12] , 4");
REQUIRE(rangeOfReadings[2] == "[43 - 47] , 7");
}

TEST_CASE("test current set 8") {
uint32_t currentInAmpere[]  = {};
sizeOfcurrentInAmpere = sizeof(currentInAmpere)/ sizeof(currentInAmpere[0]);
rangeOfReadings = consecutiveCurrentRanges(currentInAmpere, sizeOfcurrentInAmpere);
bool rangeListStatus = rangeOfReadings.empty();
REQUIRE(rangeListStatus == true);
}
/*End: Test Current Ranges*/

/*Start : Test high_fidelity_current_sensor*/

TEST_CASE("test checkIf12BitArrayWithInRange : value within boundary") {
uint32_t currentSensorValue[]  = {0, 1000, 2000, 3000, 4094};
uint32_t sizeofSensorValue = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
REQUIRE(status == true);
}

TEST_CASE("test checkIf12BitArrayWithInRange : value > boundary") {
uint32_t currentSensorValue[]  = {0, 1000, 2000, 3000, 5000};
uint32_t sizeofSensorValue = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
REQUIRE(status == false);
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value within boundary") {
uint32_t currentSensorValue[]  = {500, 1146, 1500, 2000, 2500, 3000, 3500, 4000};
uint32_t expectedCurrentValueInAmpere[] = {1, 3, 4, 5, 6, 7, 9, 10};
sizeOfcurrentSensor = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
for (uint32_t counter =0 ; counter <sizeOfcurrentSensor; counter++) {
  REQUIRE(actual12BitCurrentValueInAmpere[counter] == expectedCurrentValueInAmpere[counter]);
}
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value > boundary") {
uint32_t currentSensorValue[]  = {4095};
sizeOfcurrentSensor = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
bool currentInAmpereStatus = actual12BitCurrentValueInAmpere.empty();
REQUIRE(currentInAmpereStatus == true);
}
/*End : Test high_fidelity_current_sensor*/

/*Start : Test charging_discharging_current_sensor*/

TEST_CASE("test checkIf10BitArrayWithInRange : value within boundary") {
int32_t currentSensorValue[]  = {0, 100, 200, 300, 400, 512, 750, 1022};
uint32_t sizeofSensorValue = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
REQUIRE(status == true);
}

TEST_CASE("test checkIf10BitArrayWithInRange : value < boundary") {
int32_t currentSensorValue[]  = {-1, 100, 200, 300, 400, 512, 750, 1022};
uint32_t sizeofSensorValue = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
REQUIRE(status == false);
}

TEST_CASE("test checkIf10BitArrayWithInRange : value > boundary") {
int32_t currentSensorValue[]  = {0, 100, 200, 300, 400, 512, 750, 1023};
uint32_t sizeofSensorValue = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
REQUIRE(status == false);
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value within boundary") {
int32_t currentSensorValue[]  = {0, 512, 1022};
int32_t expectedCurrentValueInAmpere[] = {-15, 0 ,15};
sizeOfcurrentSensor = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
for (uint32_t counter =0 ; counter <sizeOfcurrentSensor; counter++) {
  REQUIRE(actual10BitCurrentValueInAmpere[counter] == expectedCurrentValueInAmpere[counter]);
}
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value out of boundary < lower boundary") {
int32_t currentSensorValue[]  = {-1};
sizeOfcurrentSensor = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
bool currentInAmpereStatus = actual10BitCurrentValueInAmpere.empty();
REQUIRE(currentInAmpereStatus == true);
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value out of boundary > upper boundary") {
int32_t currentSensorValue[]  = {1023};
sizeOfcurrentSensor = sizeof(currentSensorValue)/ sizeof(currentSensorValue[0]);
actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
bool currentInAmpereStatus = actual10BitCurrentValueInAmpere.empty();
REQUIRE(currentInAmpereStatus == true);
}

/*End : Test charging_discharging_current_sensor*/



