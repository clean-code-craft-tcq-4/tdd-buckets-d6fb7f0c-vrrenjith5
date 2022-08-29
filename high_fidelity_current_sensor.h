#ifndef __HIGH_FIDELITY_CURRENT_SENSOR_H_
#define __HIGH_FIDELITY_CURRENT_SENSOR_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define ADC_12BIT_UPPER_LIMIT (4094)
#define ADC_12BIT_LOWER_LIMIT (0)
#define ADC_12BIT_MAX_CURRENT_IN_AMPS (10)

bool checkIf12BitArrayWithInRange(uint32_t* arrayForTest, uint32_t sizeOfArray);
vector<uint32_t> adc12BitCurrentValueToAmpere(uint32_t* currentSensorValue, uint32_t sizeOfcurrentSensor);

#endif /*__HIGH_FIDELITY_CURRENT_SENSOR_H_ */


