 #include <max6675.h>

#define ntc_pin A0         // Pin,to which the voltage divider is connected
//#define vd_power_pin 2        // DONT NEED IT BECAUSE WE TAKE THE Vin FROM THE COMMON Vcc
#define nominal_resistance 100000       //Nominal resistance at 25⁰C
#define nominal_temeprature 25   // temperature for nominal resistance (almost always 25⁰ C)
#define samplingrate 5    // Number of samples 
#define beta 3950  // The beta coefficient or the B value of the thermistor (usually 3000-4000) check the datasheet for the accurate value.
#define Rref 4700   //Value of  resistor used for the voltage divider

float temperature;
int samples = 0;   //array to store the samples

void set_temp(void){
  //pinMode(vd_power_pin, OUTPUT); DONT NEED IT BECAUSE WE TAKE THE Vin FROM THE COMMON Vcc
}

void temp_read(void) {
  uint8_t i;
  float average;
  samples = 0;
  // take voltage readings from the voltage divider
 // digitalWrite(vd_power_pin, HIGH);
  for (i = 0; i < samplingrate; i++) {
    samples += analogRead(ntc_pin);
    delay(10);
  }
  //digitalWrite(vd_power_pin, LOW); DONT NEED IT BECAUSE WE TAKE THE Vin FROM THE COMMON Vcc
  average = 0;
  average = samples / samplingrate;


  // Calculate NTC resistance
  average = 1023 / average - 1;
  average = Rref / average;

  temperature = average / nominal_resistance;     // (R/Ro)
  temperature = log(temperature);                  // ln(R/Ro)
  temperature /= beta;                   // 1/B * ln(R/Ro)
  temperature += 1.0 / (nominal_temeprature + 273.15); // + (1/To)
  temperature = 1.0 / temperature;                 // Invert
  temperature -= 273.15;                    // convert absolute temp to C
        }