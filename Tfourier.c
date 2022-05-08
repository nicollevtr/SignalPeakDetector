// C program for the above approach
#include <math.h>
#include <stdio.h>

int main()
{
    int len;
    printf("Numero de elementos:\n");
    scanf("%d", &len);
    float xr[len];
    float xi[len];
    float Xr[len];
    float Xi[len];
    int i, k, n, N = len;
    FILE *fptreal;
    if ((fptreal = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\SignalPeakDetector\\samples.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    for (i = 0; i < len; i++)
    {
        fscanf(fptreal, "%f", &xr[i] ); //constroi o vetor com a parte real
    }
    fclose(fptreal);
    FILE *fptim;
    if ((fptim = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\SignalPeakDetector\\samplesIM.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    for (i = 0; i < len; i++)
    {
        fscanf(fptim, "%f", &xi[i] ); //constroi o vetor com a parte imaginara
    }
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
       // printf("(%f) + j(%f)\n\n",
         //      Xr[k], Xi[k]);
    }
    FILE *fptr;

    fptr = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\SignalPeakDetector\\transformadaReal.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        //exit(1);
    }

    for (i = 0; i < len; i++)
    {
        fprintf(fptr, "%f\n", Xr[i] ); //salva o vetor com a parte real da transformada
    }
    fclose(fptr);

    FILE *fptrIM;

    fptrIM = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\SignalPeakDetector\\transformadaIM.txt","w");

    if(fptrIM == NULL)
    {
        printf("Error!");
        //exit(1);
    }

    for (i = 0; i < len; i++)
    {
        fprintf(fptrIM, "%f\n", Xi[i] ); //salva o vetor com a parte imaginaria da transformada
    }
    fclose(fptrIM);
    printf("transformada salva!\n");

    //calcular os valores absolutos




    float Xr2[len];
    float Xi2[len];
    float magX[len];

    for (i = 0; i < len; i++)
    {
        Xr2[i] = Xr[i]*Xr[i];
        Xi2[i] = Xi[i]*Xi[i];
        magX[i] = sqrt(Xr2[i]*Xi2[i]);
    }

    FILE *fptrmag;

    fptrmag = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\SignalPeakDetector\\magnitude.txt","w");

    if(fptrmag == NULL)
    {
        printf("Error!");
        //exit(1);
    }

    for (i = 0; i < len; i++)
    {
        fprintf(fptrmag, "%f\n", magX[i] ); //salva o vetor com a parte imaginaria da transformada
    }
    fclose(fptrmag);
    printf("mag salva!\n");
    return 0;
}
