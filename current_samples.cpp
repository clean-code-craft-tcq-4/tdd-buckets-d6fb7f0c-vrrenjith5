#include "current_samples.h"

rangeAndReadings inRangeReading(int* currentInAmpere, int sizeOfcurrentInAmpere) {
  rangeAndReadings rangeReadings;
  rangeReadings.numberOfReadingsInRange = 1;
  std::sort(currentInAmpere, currentInAmpere+sizeOfcurrentInAmpere);
  for(int counter = 0; counter <sizeOfcurrentInAmpere; counter++) {
     if (((currentInAmpere[counter] + 1) == (currentInAmpere[counter +1])) || (currentInAmpere[counter] == currentInAmpere[counter+1])){
        rangeReadings.numberOfReadingsInRange++;
     }
  }
  rangeReadings.range[0] = currentInAmpere[0];
  rangeReadings.range[1] = currentInAmpere[sizeOfcurrentInAmpere -1];
  return rangeReadings;
}
