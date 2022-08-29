#include "detect_current_range.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> consecutiveCurrentRanges(uint32_t* currentInAmpere, uint32_t sizeOfcurrentInAmpere)
{
    uint32_t length = 1;
    vector<string> rangeList;

    if (sizeOfcurrentInAmpere != 0) {
      std::sort(currentInAmpere, currentInAmpere + sizeOfcurrentInAmpere);

      for(uint32_t counter = 1; counter <= sizeOfcurrentInAmpere; counter++) {
        if ((counter == sizeOfcurrentInAmpere) || ((currentInAmpere[counter] - currentInAmpere[counter - 1]) > 1)) {
          if (1 == length) {
              string singleElement = "[" + to_string(currentInAmpere[counter - length])+ "]" + " , " + to_string(length);
              rangeList.push_back(singleElement);
          }
          else {
              string rangeOfElement = "[" + to_string(currentInAmpere[counter - length]) +
                          " - " + to_string(currentInAmpere[counter - 1]) + "]" + " , " + to_string(length);
              rangeList.push_back(rangeOfElement);
          }
          length = 1; /*reset length for finding next consecutive elements in array*/
        }
        else {
          length++;
        }
      }
    }
    return rangeList;
}

