#include <stdio.h>

// Calcula a função de ativação(função sinal ou degrau bipolar)

float FuncaoAtivacao(float x)
{
  if (x < 0)
    return -1;
  else
    return 1;
}

int main(void)
{
  // Define o número de epocas
  int numEpocas = 35;
  // Define o número de amostras
  int q = 30;
  // Define as entradas do neurônio
  int Peso[30] = {113, 122, 107, 98, 115, 120, 131, 103, 96, 140, 137, 112, 106, 126, 144, 152, 139, 111, 101, 141, 157, 161, 135, 129, 154, 100, 174, 162, 148, 159};
  float pH[30] = {6.8, 4.7, 5.2, 3.6, 2.9, 4.2, 6.2, 4.2, 3.9, 7.2, 2.5, 6.5, 2.7, 7.1, 2.4, 5.7, 6.5, 6.4, 3.4, 2.2, 7.7, 4.3, 5.8, 3.7, 2.8, 6.1, 4.7, 3.4, 7.6, 3.1};
  // Define a saída desejada do neurônio
  int Y[30] = {-1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1};
  // Define o vetor de erros, o bias, a taxa de aprendizado (n) e o vetor de pesos das entradas e do bias
  float e[30], bias = -1, n = 0.1, W[3] = {0, 0, 0};

  for (int i = 0; i < numEpocas; i++)
    for (int k = 0; k < q; k++)
    {
      float X[3] = {Peso[k], pH[k], bias}, Yr, Somatorio;
      Somatorio = Peso[k] * W[0] + pH[k] * W[1] + bias * W[2];
      Yr = FuncaoAtivacao(Somatorio);
      e[k] = Y[k] - Yr;
      for (int l = 0; l < 3; l++)
      {
        W[l] += e[k] * n * X[l];
      }
    }
  printf("Vetor de erros (e) = [ ");
  for (int h = 0; h < 30; h++)
    printf("%.2f ", e[h]);
  printf("]\n");
  printf("Vetor de pesos (W) = [ %f , %f , %f ]\n", W[0], W[1], W[2]);
}