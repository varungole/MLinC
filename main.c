#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define train_count (sizeof(train)/sizeof(train[0]))

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

float rand_float(void) {
   return (float)rand()/ (float)RAND_MAX;
}

float cost(float w, float b) {
   float result = 0.0f;
   for (size_t i=0; i<train_count; i++) {
      float x = train[i][0];
      float y = x*w + b;
      float d = y - train[i][1];
      result += d*d;
   }
   result /= train_count;
   return result;
}

int main() {
    srand(time(0)); //seed

    float w = rand_float()*10.0f;
    float b = rand_float()* 5.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", cost(w, b));

    //y = 2x + bias???
    for(size_t i=0;i<7000;++i) {
       float dW =  (cost(w+eps, b) - cost(w, b))/eps;
       float dB = (cost(w, b+eps) - cost(w, b))/eps;
       w -= rate*dW;
       b -= rate*dB;
       printf("cost = %f, w= %f, b=%f \n", cost(w, b), w, b);
    }

    printf("%f\n", w);
    printf("%f\n", b);
    return 0;
}
