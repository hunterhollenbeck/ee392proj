// Avoid IDE problems by defining struct in septate .h file.
// Pad record so size is a power of two for best write performance.
#ifndef ExFatLogger_h
#define ExFatLogger_h
const size_t ADC_COUNT = 3;
struct data_t {
  float adc[ADC_COUNT];
};
#endif  // ExFatLogger_h