#include <iostream>
#include <string>
#include "ArrayDyn.hpp"

using namespace std;

// Une petite classe maison pour tester
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void afficher() const { cout << "(" << x << "," << y << ")"; }
};

int main() {
    cout << "Test du conteneur ArrayDyn " << endl;

    // Test 1 : avec des int
    ArrayDyn<int> nombres;
    nombres.push_back(10);
    nombres.push_back(20);
    nombres.push_back(30);

    cout << "\n Test avec int" << endl;
    // Boucle range-based for (utilise begin() et end())
    for (auto& n : nombres) {
        cout << n << " ";
    }
    cout << endl;

    // Test 2 : avec des string
    ArrayDyn<string> mots;
    mots.push_back("Bonjour");
    mots.push_back("le");
    mots.push_back("monde");

    cout << "\n Test avec string " << endl;
    for (auto& m : mots) {
        cout << m << " ";
    }
    cout << endl;

    // --- Test 3 : avec un objet maison ---
    ArrayDyn<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(3, 4));

    cout << "\nTest avec objet maison " << endl;
    for (auto& p : points) {
        p.afficher();
        cout << " ";
    }
    cout << endl;

    // Test 4 : La copie (Rule of Three) 
    cout << "\nTest de la copie" << endl;
     // Utilise le constructeur de copie
    ArrayDyn<int> copie = nombres;
    copie.push_back(40);          
    cout << "Original : ";
    for (auto& n : nombres) cout << n << " ";
    cout << "\nCopie    : ";
    for (auto& n : copie) cout << n << " ";
    cout << endl;

    return 0;
}