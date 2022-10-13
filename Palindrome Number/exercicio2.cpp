#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x); // converte a entrada para string
        bool resultado = true; // inicializa o resultado da análise com falso
        int i; // contador

        for ((i = 0); (i < (s.length() / 2)); i++) {
            if (s [i] != s[(s.length() - 1 - i)]) {
                resultado = false;
            }
        }

        return resultado;
    }
};

int main() {
    Solution solucao;

    int entrada;

    entrada = 12331;

    printf ("Inteiro de entrada: %d\n\r", entrada);

    if (solucao.isPalindrome (entrada)) {
        printf ("O numero entrado e palindromo.");
    }
    else {
        printf ("O numero entrado NAO e palindromo.");
    }
}