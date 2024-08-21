#ifndef TERM_H
#define TERM_H

#include <string>
#include <iostream>
#include <algorithm> 

class Term
{
private:
    std::string term;
    long weight;

public:
    Term();
    Term(std::string term, long weight);
    static int compareByWeight(Term T1, Term T2);
    static int compareByPrefix(Term T1, Term T2, int r);
    bool operator<(const Term &T2) const;
    friend std::ostream &operator<<(std::ostream &out, const Term &t);
    std::string getTerm() const;
    long getWeight() const;
};

#endif // TERM_H
