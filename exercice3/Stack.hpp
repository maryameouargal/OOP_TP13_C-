#ifndef STACK_HPP
#define STACK_HPP

#include <memory>   
#include <cstddef>  
#include "StackExceptions.hpp"

template <typename T>
class Stack {
private:
// Memoire geree automatiquement !
    std::unique_ptr<T[]> data; 
    std::size_t capacite;
    // Indice du prochain element libre
    std::size_t top_index;     

public:
    // 1. Constructeur avec capacite (par defaut 10)
    Stack(std::size_t cap = 10) 
        : data(new T[cap]), capacite(cap), top_index(0) {}

    // 2. Constructeur a partir d'un iterateur (begin, end)
    template <typename Iterator>
    Stack(Iterator begin, Iterator end) {
        // On compte d'abord le nombre d'elements
        std::size_t count = 0;
        for (Iterator it = begin; it != end; ++it) {
            count++;
        }
        
        capacite = count;
        data = std::unique_ptr<T[]>(new T[capacite]);
        top_index = 0;
        
        // On copie les elements
        for (Iterator it = begin; it != end; ++it) {
            data[top_index] = *it;
            top_index++;
        }
    }

    // 3. push : ajouter un element au sommet
    void push(const T& element) {
        if (top_index >= capacite) {
            throw StackOverflow(); // Lance notre exception !
        }
        data[top_index] = element;
        top_index++;
    }

    // 4. pop : retirer l'element du sommet
    void pop() {
        if (top_index == 0) {
            throw StackUnderflow();
        }
        top_index--;
    }

    // 5. peek : regarder le sommet sans le retirer
    T peek() const {
        if (top_index == 0) {
            throw StackUnderflow();
        }
        return data[top_index - 1];
    }

    // 6. empty : la pile est-elle vide ?
    bool empty() const {
        return top_index == 0;
    }

    // 7. size : nombre d'elements actuel (bonus pratique)
    std::size_t size() const {
        return top_index;
    }
};

#endif