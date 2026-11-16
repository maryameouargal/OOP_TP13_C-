#include <iostream>
#include "Matrice.hpp"

using namespace std;

int main() {
    cout << " Test avec des entiers (2x2)" << endl;
    
    // Creation de deux matrices 2x2
    Matrice<int, 2, 2> A = { 1, 2, 
                             3, 4 };
    Matrice<int, 2, 2> B = { 5, 6, 
                             7, 8 };

    cout << "Matrice A :\n" << A;
    cout << "Matrice B :\n" << B;

    cout << "A + B :\n" << (A + B);
    cout << "A - B :\n" << (A - B);
    cout << "A * B (produit) :\n" << (A * B);

    cout << "\nTest avec des doubles (2x3 et 3x2)" << endl;
    
    // F est de taille 2x3
    Matrice<double, 2, 3> F = { 1.5, 2.0, 3.0,
                                4.0, 5.0, 6.0 };
    
    // G est de taille 3x2
    Matrice<double, 3, 2> G = { 1.0, 2.0,
                                3.0, 4.0,
                                5.0, 6.0 };

    cout << "Matrice F (2x3) :\n" << F;
    cout << "Matrice G (3x2) :\n" << G;

    // Le resultat sera de taille 2x2
    cout << "F * G (resultat 2x2) :\n" << (F * G);

    return 0;
}