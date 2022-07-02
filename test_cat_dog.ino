//Logistic regression training on uno
//cat dog prediction using height and weight
//Test the model
//weight and bias exported from trained models
#define n_features 2
#define samples 5 //five test samples
//array format [x0,x1 for 1st row and so on]
float X[]={0.2,0.1,0.55,0.65,0.231,0.475,0.15,0.373,0.65,0.76};//test samples

float ytrue[] = {0,1,0,0,1};
float w[] = {7.16642 ,4.63978};
float b=-5.63096;
float tmp[2];//to fetch test data

float sigmoid(float x)
// sigmoid activation is coded
{
double y = 1/(1+exp(-x));
return y;
}
//code for n-input neuron with sigmoid activation
float neuron(float W[],float B, float X[],int nn) //n is feature size
{
  float z,y = 0.0;
  for(int i=0; i < nn; i++)
  {
     y += W[i]*X[i];
  }
  y += B;
  z = sigmoid(y);
  return z;
}
void setup() {
  float y[samples];
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  //****** Prediction using evaluated model **//
Serial.println(F("\nPredicted values: "));
  unsigned int t1=millis();
  float t2=0;
  int j=0;
for(int i=0; i< samples; i++) //4 is total training data len
{
  j = n_features*i;
  tmp[0] = X[j];
  tmp[1] = X[j+1];
   y[i] = neuron(w,b,tmp,n_features);
   //Serial.print("\n");
  // Serial.println(y[i],5);
   //j = i+2;
   if(y[i]>0.5)
   y[i]=1;
   else
   y[i]=0;
  Serial.print(y[i],2);
  Serial.print(F("\t"));
}
t2 = (millis()-t1);
Serial.print(F("\nTime elapsed: "));
Serial.print(t2,2);
Serial.print(F(" mS"));
  }

void loop() {
  // put your main code here, to run repeatedly:

}
