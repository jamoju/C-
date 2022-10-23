#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
public:
    void imprimeVetor (std::vector<int>& nums) {
        int i;

        printf ("frequency: [");

        for (i = 0; i < 26; i++) {
            printf ("%d", nums [i]);

            if (i < 25) {
                printf (", ");
            }
        }

        printf ("]\n\r\n\r");
    }

    bool equalFrequency(std::string word) {
        std::vector <int> frequency (26);
        int i,
            higherFreq = 0,
            secHigherFreq = 0,
            countHigherFreq = 0,
            countSecHigherFreq = 0;

        // inicializa o vetor de frequencia de ocorrências com 0
        for (i = 0; i < 26; i++) {
            frequency [i] = 0;
        }

        // conta quantas ocorrências cada letra teve
        for (i = 0; i < word.size (); i++) {
            frequency [word [i] - 'a']++;
        }

//printf ("inicio\r\n");
//imprimeVetor (frequency);

        // acha a maior e a segunda maior frequências de ocorrências (valores distintos e diferentes de 0)
        for (i = 0; i < 26; i++) {
            if (frequency [i] > higherFreq) {
                secHigherFreq = higherFreq;
                higherFreq = frequency [i];
            } else if ((frequency [i] != higherFreq) && (frequency [i] > secHigherFreq)) {
                secHigherFreq = frequency [i];
            } 
        }

//printf ("higherFreq: %d\r\n", higherFreq);
//printf ("secHigherFreq: %d\r\n", secHigherFreq);

        // conta quantas vezes cada uma das duas maiores frequências (diferentes de 0) ocorrem
        // caso haja uma terceira frequência diferente das duas encontradas, retorna false pq não é possível normalizar
        for (i = 0; i < 26; i++) {
            if (frequency [i] != 0) {
                if (frequency [i] == higherFreq) {
                    countHigherFreq++;
                } else if (frequency [i] == secHigherFreq) {
                    countSecHigherFreq++;
                } else {
                    return false;
                }
            }
        }

//printf ("countHigherFreq: %d\r\n", countHigherFreq);
//printf ("countSecHigherFreq: %d\r\n", countSecHigherFreq);

        // só se pode deletar caracteres com a maior ou a segunda maior frequências
        // (1) se não existe uma segunda maior frequência diferente de 0 então ou a maior frequência é igual a 1
        //     ou tem uma diferença de 1 para a segunda maior frequência
        // (2) se for o caso de deletar o caractere com a segunda maior frequência então só pode ser se ela for igual a 1 e ocorrer só uma vez
        // (3) se for o caso de deletar o caractere com a maior frequência então ela só pode ocorrer uma vez e
        //     tem que ter a diferença de 1 da segunda maior frequencia

//if ((countHigherFreq == 1) && ((higherFreq - 1) == secHigherFreq)) {
//    printf ("caso (3)\n\r");
//    return true;
//}

        return (((secHigherFreq == 0) && ((higherFreq == 1) || (countHigherFreq == 1))) ||
                ((secHigherFreq == 1) && (countSecHigherFreq == 1)) ||
                ((countHigherFreq == 1) && ((higherFreq - 1) == secHigherFreq)));
    }
};

int main() {

    Solution solucao;

    std::string strEntrada = "";

    printf ("Digite o string de entrada (\"Q\" para sair): ");

    std::cin >> strEntrada;

    while (strEntrada != "Q") {
        if (solucao.equalFrequency (strEntrada)) {
            printf ("solucao.equalFrequency (strEntrada) = TRUE\n\r\n\r");
        } else {
            printf ("solucao.equalFrequency (strEntrada) = FALSE\n\r\n\r");
        }

        printf ("Digite o string de entrada (\"Q\" para sair): ");

        std::cin >> strEntrada;
    }
    
    return 0;
}