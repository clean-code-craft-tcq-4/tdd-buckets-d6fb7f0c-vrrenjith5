#ifndef __CURRENT_SAMPLES_H_
#define __CURRENT_SAMPLES_H_

typedef struct {
  int numberOfReadingsInRange;
  int range[2];
}rangeAndReadings;

rangeAndReadings inRangeReading(int* currentInAmpere, int sizeOfcurrentInAmpere);

#endif /*__CURRENT_SAMPLES_H_ */
