#include "Term.h"

std::string Term::getTerm() const
{
    return term;
}

long Term::getWeight() const
{
    return weight;
}

Term::Term() : term(""), weight(0) {}

Term::Term(std::string term, long weight) : term(term), weight(weight) {}

int Term::compareByWeight(Term T1, Term T2)
{
    if (T1.weight > T2.weight)
    {
        return -1;
    }
    else if (T1.weight < T2.weight)
    {
        return 1;
    }
    return 0;
}

int Term::compareByPrefix(Term T1, Term T2, int prefixLength)
{
    prefixLength = std::min(prefixLength, static_cast<int>(std::min(T1.term.size(), T2.term.size())));

    std::string prefix1 = T1.term.substr(0, prefixLength);
    std::string prefix2 = T2.term.substr(0, prefixLength);

    std::transform(prefix1.begin(), prefix1.end(), prefix1.begin(), ::tolower);
    std::transform(prefix2.begin(), prefix2.end(), prefix2.begin(), ::tolower);

    if (prefix1 < prefix2)
    {
        return -1;
    }
    else if (prefix1 > prefix2)
    {
        return 1;
    }
    return 0;
}

bool Term::operator<(const Term &T2) const
{
    return term < T2.term;
}

std::ostream &operator<<(std::ostream &out, const Term &t)
{
    out << t.getTerm() << " (" << t.getWeight() << ")";
    return out;
}
