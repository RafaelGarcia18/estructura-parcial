#include <stdio.h>
int main(void)
{
    int mensajeV =0;
    int tamano;
    //conprobacion de insercion correcta de tamaño de matriz
    do
    {
        if(mensajeV>1)
        {
            printf("Numero incorrecto intente otra vez");
        }
        printf("Ingrese el tamaño de la matriz\nNotas: \n**la matriz se generara cuadrada\n**No debe ser menor o igual a uno\n");
        scanf("%d",&tamano);
        mensajeV++;
    }
    while(tamano<=0);
    //declaracion de matriz
    int matriz [tamano][tamano];
    //llenado de matriz
    for(int i=0; i<tamano; i++)
    {
        for (int o=0; o<tamano; o++)
        {
            printf("Ingrese el valor de la matriz amiga en la posicion %d,%d\n",i,o);
            scanf("%d",&matriz[i][o]);
        }
    }
    //determinar el numero a comparar (numero amigo)
    int numeroAmigo=0;
    for(int v =0; v<tamano; v++)
    {
        numeroAmigo = numeroAmigo + matriz[0][v];
    }
    //declaracion de variable tipo flag(int siAmigo) y variable temporar para calculos
    int siAmigo=0,temp;
    //conprobar filas
    for(int i=0; i<tamano; i++)
    {
        temp = 0;
        for (int o=0; o<tamano; o++)
        {
            temp = temp + matriz[i][o];
        }
        if(temp == numeroAmigo)
        {
            siAmigo ++;
        }
    }
    //determinar si las filas con amigas
    if(siAmigo == tamano)
    {
        for (int o=0; o<tamano; o++)
        {
            temp=0;
            for(int i=0; i<tamano; i++)
            {
                temp = temp + matriz[i][o];
            }
            if(temp == numeroAmigo)
            {
                siAmigo++;
            }
        }
        //recorrer de forma diagonal decreciente la matriz y comprobar si es amigo
        temp=0;
        for(int i =0; i<tamano; i++)
        {
            temp =temp + matriz [i][i];
        }
        if(temp == numeroAmigo)
        {
            siAmigo++;
        }
        //recorrer de forma diagonal creciente la matriz y comprobar si es amigo
        int decreciente = (tamano-1);
        temp =0;
        for(int i=0; i<tamano; i++)
        {
            temp = temp + matriz [i][decreciente];
            decreciente--;
        }
        if(temp == numeroAmigo)
        {
            siAmigo++;
        }
        //comprobar que todas las filas, columnas y diagonales son amigas
        if(siAmigo == ((2*tamano)+2))
        {
            printf("\n*****************************************************\n\tEs una matriz amiga\n*****************************************************");
        }
    }
    else
    {
        printf("\n*****************************************************\n\tNO es una matriz amiga\n*****************************************************");

    }
}
