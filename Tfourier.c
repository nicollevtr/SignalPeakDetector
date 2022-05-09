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
    if ((fptreal = fopen("C:\\Users\\nicol\\Documents\\4o ANO ELO\\estagio\\codigos\\ps04_samples.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    for (i = 0; i < len; i++)
    {
        fscanf(fptreal, "%f    %f", &xr[i],&xi[i] ); //le as amostras no arquivo e constroi um vetor com a parte real e outro com a parte im
    }
    fclose(fptreal);
    for (k = 0; k < N; k++)
    {
        Xr[k] = 0;
        Xi[k] = 0;
        for (n = 0; n < len; n++)
        {
            Xr[k]
                = (Xr[k]
                   + xr[n] * cos(2 * 3.14159265359 * k * n / N)
                   + xi[n] * sin(2 * 3.14159265359 * k * n / N)); //parte real da TF
            Xi[k]
                = (Xi[k]
                   - xr[n] * sin(2 * 3.14159265359 * k * n / N)
                   + xi[n] * cos(2 * 3.14159265359 * k * n / N)); //parte imaginaria da TF
        }
    }
    /*
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
    */
    //calcular os valores absolutos

    float Xr2[len];
    float Xi2[len];
    float magX[len];
    for (i = 0; i < len; i++)
    {
        Xr2[i] = Xr[i]*Xr[i];
        Xi2[i] = Xi[i]*Xi[i];
        magX[i] = sqrt(Xr2[i]+Xi2[i]); //modulo
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
        fprintf(fptrmag, "%f\n", magX[i] ); //salva o vetor com o módulo da transformada
    }
    fclose(fptrmag);
    int nn = sizeof(magX) / sizeof(magX[0]);
    float max = magX[0];
    int index;
    for (i = 0; i < nn; i++)
    {
        //Compare elements of array with max
        if(magX[i] > max)
        {
            max = magX[i]; //encontrar o valor maximo
            //  printf("%f",max);
            index=i;
            // printf("%f",i);
        }
    }
    printf("Maximo: %f na posicao %d\n", max,index+1);
    float freq=index*9.6;
    printf("Frequencia: %f Hz\n",freq);
    return 0;
}
