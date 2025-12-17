#include "catch.hpp"

// Zad2
// tutaj definicja klasy Makaron
// BEZ definicji metody gotujMakaron (tylko z deklaracją)

class Makaron
{
public:

    virtual ~Makaron() = default;

    virtual double ileMaki(unsigned P) const { return 0; }
    Makaron static gotujMakaron(const std::string& s) 
    { 
        Makaron* m;
        if (s.front() == s.back())
        {
            m = new Tagliatelle(3.14, 0.42, 0.1);
        }
        else
        {
            m = new Penne();
        }
        return *m; 
    }

    
};

// Zad1
// tutaj definicja klasy Tagliatelle


class Tagliatelle : public Makaron
{
public:
    Tagliatelle() : R{0.5}, L{0.5}, W{0.5} {};
    Tagliatelle(double l, double w, double r) : L{l}, R{r}, W{w} {};
    ~Tagliatelle() {};

    double ileMaki(unsigned P) const override { return P * L * W * (1. - R) * C; }

private:
    double W; //szerokosc
    double L; //dlugosc
    double R; //proporcja
    static const double C;
};

class Penne : public Makaron
{
public:

    double ileMaki(unsigned P) const override { return (double)P; }
};