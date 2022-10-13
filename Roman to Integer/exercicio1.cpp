#include <string>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string s) {
        std::string sRomanNumeral;
        int iIntegerNumeral = 0,
            i; // string counter

        for (i = 0; i < s.length (); i++) {
            switch (s [i]) {
                case 'I':
                    if (s [i + 1] != '\0') {
                        if ((s [i + 1] == 'V') ||
                            (s [i + 1] == 'X')) {
                            iIntegerNumeral--; // I is left of either a V or a X, subtract 1 
                        }
                        else {
                            iIntegerNumeral++; // I is the last digit, add 1
                        }
                    }
                    else { 
                        iIntegerNumeral++; // I is the last digit, add 1
                    }
                    
                    break;

                case 'V':
                    iIntegerNumeral = iIntegerNumeral + 5; // add 5

                    break;

                case 'X':
                    if (s [i + 1] != '\0') {
                        if ((s [i + 1] == 'L') ||
                            (s [i + 1] == 'C')) {
                            iIntegerNumeral = iIntegerNumeral - 10; // X is left of either a V or a X, subtract 10 
                        }
                        else {
                            iIntegerNumeral = iIntegerNumeral + 10; // X is the last digit, add 10
                        }
                    }
                    else { 
                        iIntegerNumeral = iIntegerNumeral + 10; // add 10
                    }
                    
                    break;

                case 'L':
                    iIntegerNumeral = iIntegerNumeral + 50; // add 50

                    break;
                    
                case 'C':
                    if (s [i + 1] != '\0') {
                        if ((s [i + 1] == 'D') ||
                            (s [i + 1] == 'M')) {
                            iIntegerNumeral = iIntegerNumeral - 100; // C is left of either a V or a X, subtract 100 
                        }
                        else {
                            iIntegerNumeral = iIntegerNumeral + 100; // C is the last digit, add 100
                        }
                    }
                    else { 
                        iIntegerNumeral = iIntegerNumeral + 100; // add 100
                    }
                    
                    break;
                case 'D':
                    iIntegerNumeral = iIntegerNumeral + 500; // add 500

                    break;

                case 'M':
                    iIntegerNumeral = iIntegerNumeral + 1000; // add 1000

                    break;

                default:
                    break;
            }    
        }
            
        return iIntegerNumeral;
    }
};

int main() {
    Solution solucao;

    int result;
    std::string entrada;

    entrada = "XCIV";

    printf ("string de entrada: ");

    std::cout << entrada + "\n\r";

    result = solucao.romanToInt (entrada);

    printf ("convertido para algarismos arabicos: %d", result);
}