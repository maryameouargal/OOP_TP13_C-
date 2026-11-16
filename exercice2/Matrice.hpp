#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <stdexcept>

template <typename T, int LIGNES, int COLS>
class Matrice {
    // On autorise toutes les versions de Matrice a acceder aux donnees privees
    template <typename U, int L, int C> friend class Matrice;

private:
    T donnees[LIGNES][COLS];

public:
    // 1. Constructeur par defaut (remplit de 0)
    Matrice() {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLS; j++) {
                donnees[i][j] = T(0);
            }
        }
    }

    // 2. Constructeur avec liste d'initialisation
    Matrice(std::initializer_list<T> liste) {
        if (liste.size() != LIGNES * COLS) {
            throw std::invalid_argument("Erreur : nombre d'elements incorrect.");
        }
        int pos = 0;
        for (const T& val : liste) {
            donnees[pos / COLS][pos % COLS] = val;
            pos++;
        }
    }

    // 3. Surcharge de l'addition (+)
    Matrice<T, LIGNES, COLS> operator+(const Matrice<T, LIGNES, COLS>& autre) const {
        Matrice<T, LIGNES, COLS> res;
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLS; j++) {
                res.donnees[i][j] = donnees[i][j] + autre.donnees[i][j];
            }
        }
        return res;
    }

    // 4. Surcharge de la soustraction (-)
    Matrice<T, LIGNES, COLS> operator-(const Matrice<T, LIGNES, COLS>& autre) const {
        Matrice<T, LIGNES, COLS> res;
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLS; j++) {
                res.donnees[i][j] = donnees[i][j] - autre.donnees[i][j];
            }
        }
        return res;
    }

    // 5. Surcharge de la multiplication (*)
    // Attention : le resultat change de dimension (LIGNES x COLS_MATRICE2)
    template <int NOUVELLES_COLS>
    Matrice<T, LIGNES, NOUVELLES_COLS> operator*(const Matrice<T, COLS, NOUVELLES_COLS>& autre) const {
        Matrice<T, LIGNES, NOUVELLES_COLS> res;
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < NOUVELLES_COLS; j++) {
                for (int k = 0; k < COLS; k++) {
                    res.donnees[i][j] += donnees[i][k] * autre.donnees[k][j];
                }
            }
        }
        return res;
    }

    // 6. Surcharge de l'affichage (<<)
    friend std::ostream& operator<<(std::ostream& os, const Matrice<T, LIGNES, COLS>& mat) {
        for (int i = 0; i < LIGNES; i++) {
            for (int j = 0; j < COLS; j++) {
                os << mat.donnees[i][j] << "\t";
            }
            os << "\n";
        }
        return os;
    }
};

#endif