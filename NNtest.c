#include<stdio.h>
#include<stdlib.h>


typedef struct neuron{
    float d_Etotal;
    float d_Out;
    float d_Net;
    float *weights;
    int weightssize;
}Neuron;

typedef struct layer{
    Neuron **neurons;
    int size;
}Layer;

typedef struct network{
    Layer **layers;
    int size;
}Network;

void CreateNetwork(Network *NeuralNetwork){
    int NumOfLayers,NumOfNeurons,NumOfPreviousNeurons;

    printf("Type the number of desired hiden layers: ");
    scanf("%d",&NumOfLayers);
    NumOfLayers+=2;
    NeuralNetwork->size=NumOfLayers;
    NeuralNetwork->layers=malloc(NumOfLayers*sizeof(Layer*));

    for(int i=0;i<NumOfLayers;i++){
        if(i==0) printf("Type the numbers of disered neurons in the input layer: ");
        else if(i<=(NumOfLayers-2)) printf("Type the number of disered neurons int the hiden layer No. %d: ",i);
        else printf("Type the number of desired neurons in the output layer: ");
        scanf("%d",&NumOfNeurons);
        NeuralNetwork->layers[i]->size=NumOfNeurons;
        NeuralNetwork->layers[i]->neurons=malloc(NumOfNeurons*sizeof(Neuron*));
        if(i>0){
            for(int j=0;j<NumOfNeurons;j++){
                NumOfPreviousNeurons=(NeuralNetwork->layers[i-1])->size;
                NeuralNetwork->layers[i]->neurons[j]->weights=malloc(NumOfPreviousNeurons*sizeof(float));
                for(int k=0;k<NumOfPreviousNeurons;k++) NeuralNetwork->layers[i]->neurons[j]->weights[k]=((float)(rand()%1000001))/1000000.0;
                NeuralNetwork->layers[i]->neurons[j]->weightssize=NumOfPreviousNeurons;
            }
        }
        else{
            for(int j=0;j<NumOfNeurons;j++){
                NeuralNetwork->layers[i]->neurons[j]->weights=NULL;                
                NeuralNetwork->layers[i]->neurons[j]->weightssize=0;
            }
        }
    }
    return;
}

void PrintAll(Network *NeuralNetwork){
    int NumOfLayers,NumOfNeurons,NumOfWeights;    
    NumOfLayers=NeuralNetwork->size;
    for(int i=0;i<NumOfLayers;i++){
        if(i==0) printf("Input Layer:\n");
        else if(i<=NumOfLayers) printf("Hiden Layer No. %d out of %d:\n",i,(NumOfLayers-2));
        else printf("Output layer:\n");
        NumOfNeurons=NeuralNetwork->layers[i]->size;
        for(int j=0;j<NumOfNeurons;j++){
            printf("\tNeuron No. %d out of %d",(j+1),NumOfNeurons);
            NumOfWeights= NeuralNetwork->layers[i]->neurons[j]->weightssize;
            for(k=0;j<NumOfWeights;j++)
        }


    }



}
int main(void){
    Network *NeuralNetwork=malloc(1*sizeof(Network));
    CreateNetwork(NeuralNetwork);
    PrintAll(NeuralNetwork);

    return 0;

}