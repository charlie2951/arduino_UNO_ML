//Logistic regression training on uno
//cat dog prediction using height and weight
#define learning_rate 0.05
#define epoch 5000
#define n_features 2
#define samples 8
float X[]={0.9,0.7,0.7,0.8,0.3,0.4,0.2,0.3,0.6,0.6,0.8,0.7,0.2,0.2,0.25,0.35};

float ytrue[] = {1,1,0,0,1,1,0,0};
float w[] = {0.1,0.1};
float b=0.2;
float tmp[2];
float dw1,dw2,db;
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
//calculate cross entropy loss
float loss_crossentropy(float ytrue[], float ypred[])
{
  float loss= 0;
for(int i=0;i<samples;i++)
{
  loss += -ytrue[i]*log(ypred[i])-(1-ytrue[i])*log(1-ypred[i]);
}
loss /=samples; //length of test data is 4
return loss;
}
//Gradient Descent algorithm
void gradient_descent(float ytrue[], float ypred[])
{
//float loss= 0;
dw1=0;
dw2=0;
db=0;
for(int i=0;i<samples;i++)
{
  db += (ypred[i]-ytrue[i]);
 int jj = 2*i;
 dw1 += X[jj]*(ypred[i]-ytrue[i]);
 dw2 += X[jj+1]*(ypred[i]-ytrue[i]);
}
//for(int k=0;k<samples;k++)
//{
 // int jj = 2*k;
 //dw1 += X[jj]*db;
 //dw2 += X[jj+1]*db;
//}
db /= samples; //length of test data is 4
dw1 /= samples;
dw2 /= samples;

}

void setup() {
  float y[samples];
  int n=0;
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("Training the model..."));
  unsigned int t1=millis();
  float t2=0;
  while(n <= epoch){ //start the training loop for num of epoch
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
}
float loss = loss_crossentropy(ytrue,y);
float accuracy = 1-loss;
Serial.print(F("\nNumber of Epoch: "));
Serial.print(n);
Serial.print(F("\nTraining Loss: "));
Serial.print(loss,5);
Serial.print(F("\tAccuracy: "));
Serial.print(accuracy,2);
//call gradient descent
gradient_descent(ytrue,y);
w[0] -= learning_rate * dw1;
w[1] -= learning_rate * dw2;
b -= learning_rate * db;
n += 1;
/*Serial.print("\n");
Serial.print(w[0],5);
Serial.print("\t");
Serial.print(w[1],5);
Serial.print("\n");
*/
}
Serial.print(F("\nTraining Completed Successfully... "));
Serial.println(F("\nPrinting Weights and bias values: w[0],w[1],b->"));
Serial.print("\n");
Serial.print(w[0],5);
Serial.print("\t");
Serial.print(w[1],5);
Serial.print("\t");
Serial.print(b,5);

t2 = (millis()-t1)/1000;
Serial.print(F("\nTime elapsed: "));
Serial.print(t2,2);
Serial.print(F(" Sec"));

//****** Prediction using evaluated model **//
Serial.println(F("\nPredicted values: "));
int j=0;
for(int i=0; i< samples; i++) //4 is total training data len
{
  j = n_features*i;
  tmp[0] = X[j];
  tmp[1] = X[j+1];
   y[i] = neuron(w,b,tmp,n_features);
   //Serial.print("\n");
   if(y[i]>0.5)
   y[i]=1;
   else
   y[i]=0;
  Serial.print(y[i],2);
  Serial.print(F("\t"));
   //j = i+2;
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
