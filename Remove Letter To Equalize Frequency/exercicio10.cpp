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
        int i;

        // inicializa o vetor de frequencia de ocorrências com 0
        for (i = 0; i < 26; i++) {
            frequency [i] = 0;
        }

        // conta quantas ocorrências cada letra teve
        for (i = 0; i < word.size (); i++)
        {
            frequency [word [i] - 'a']++;
        }

        printf ("Antes\r\n");

        imprimeVetor (frequency);

        return true;        
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