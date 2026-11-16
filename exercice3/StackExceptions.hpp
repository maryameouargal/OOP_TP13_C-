#ifndef STACKEXCEPTIONS_HPP
#define STACKEXCEPTIONS_HPP

#include <exception>

// Exception personnalisee : quand la pile est pleine
class StackOverflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est pleine (StackOverflow).";
    }
};

// Exception personnalisee : quand la pile est vide
class StackUnderflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide (StackUnderflow).";
    }
};

#endif