#include <PID_v1.h>

double Setpoint;//desired value
double Input;//photo sensroe LDR
double Output;//

///PID parameters
double Kp=0, Ki=10, Kd=0;
///Create PID instance
PID mypid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
void setup() {
  Serial.begin(9600);
  //Hardcode the brigdness
  Setpoint = 75; 
  //Turn the PID on
  mypid.SetMode(AUTOMATIC);
  //Adjust PID values
  mypid.SetTunings(Kp,Ki,Kd);
}

void loop() {
  // Read the value from LDR, Analog input:0 to 1024...then mapping
  Input = map(analogRead(5),0, 1024, 0, 255);
  //PID calculation
  mypid.Compute();
  //write the output as calculated by PID functions
  analogWrite(3, Output);///LED is set to D3 PWM pin

  Serial.print(Input);
  Serial.println(" ");
  Serial.println(Output);
  Serial.println(" ");
  Serial.println(Setpoint);
  Serial.println();
}
