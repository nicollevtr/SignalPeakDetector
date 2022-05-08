// C program for the above approach
#include <math.h>
#include <stdio.h>

// Function to calculate the DFT
void calculateDFT(int len)
{
    float xr[len];
    float xi[len];
    float Xr[len];
    float Xi[len];
    int i, k, n, N = len;
  //  printf("Enter the number of "
     //      "points in the DFT: ");
    //scanf("%d", &N);
    FILE *fptreal;
    if ((fptreal = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\codigos\\samples.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    for (i = 0; i < len; i++)
    {
        fscanf(fptreal, "%f", &xr[i] ); //constroi o vetor com a parte real
    }
    fclose(fptreal);
    FILE *fptim;
    if ((fptim = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\codigos\\samplesIM.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    for (i = 0; i < len; i++)
    {
        fscanf(fptim, "%f", &xi[i] ); //constroi o vetor com a parte imaginara
    }
//    for (i = 0; i < len; i++)
//    {
//        printf("%f", xr[i] ); //PRINTA o vetor com a parte imaginara
//    }
//    for (i = 0; i < len; i++)
//  {
//        printf("%f", xi[i] ); //PRINTA o vetor com a parte imaginara
//  }
//  printf("Number of elements: %d\n", sizeof(xr)/sizeof(xr[0]));
//  printf("last element: %f\n", xr[len-1]);
//  printf("number of elements: %d\n", sizeof(xi)/sizeof(xi[0]));
//  printf("last element: %f\n", xi[len-1]);
    fclose(fptim);
    for (k = 0; k < N; k++)
    {
        Xr[k] = 0;
        Xi[k] = 0;
        for (n = 0; n < len; n++)
        {
            Xr[k]
                = (Xr[k]
                   + xr[n] * cos(2 * 3.141592 * k * n / N)
                   + xi[n] * sin(2 * 3.141592 * k * n / N));
            Xi[k]
                = (Xi[k]
                   - xr[n] * sin(2 * 3.141592 * k * n / N)
                   + xi[n] * cos(2 * 3.141592 * k * n / N));
        }
        printf("(%f) + j(%f)\n\n",
               Xr[k], Xi[k]);
    }
}

int main()
{
    int tam;
    printf("Numero de elementos:\n");
    scanf("%d", &tam);
    calculateDFT(tam);
    return 0;
}
