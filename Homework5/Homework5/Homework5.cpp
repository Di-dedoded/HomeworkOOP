#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class Pair1
{
private:
    T m_a, m_b;
public:
    Pair1(T a, T b)
        :m_a(a), m_b(b)
    {
    }
    T first() const
    {
        return m_a;
    }
    T second() const
    {
        return m_b;
    }
    ~Pair1()
    {
    }
};

template <class T1, class T2>
class Pair
{
protected:
    T1 m_a;
    T2 m_b;
public:
    Pair(T1 a, T2 b)
        :m_a(a), m_b(b)
    {
     //   cout << "Pair(T1 a, T2 b)" << endl;
    }
    T1 first() const
    {
        return m_a;
    }
    T2 second() const
    {
        return m_b;
    }
    ~Pair()
    {
    }
};

template <class T2>
class StringValuePair : public Pair<string, T2>
{
public:
    StringValuePair(string str, T2 b)
        :Pair<string, T2>(str, b)
    {
        //cout << "StringValuePair(string& str, T b) " << endl;
    }

};

class Card
{

public:
    enum rank
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHTH, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit
    {
        CLUBS, TAMBOURINES, HEARTS, SPADES
    };
private:
    rank m_rank;
    suit m_suit;
    bool m_isFaceUp;
public:
    Card(rank r = ACE, suit s = CLUBS, bool ifu = true)
        :m_rank(r), m_suit(s), m_isFaceUp(ifu)
    {

    }
    int getValue() const
    {
        int value = 0;
        if (m_isFaceUp)
        {
            value = m_rank;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }
    void flip()
    {
        m_isFaceUp = !(m_isFaceUp);
    }
};

class Hand
{
private:
    vector<Card*> m_Cards;
public:
    Hand()
    {
        m_Cards.reserve(8);
    }
    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }
    void Clear()
    {
        vector<Card*>::iterator it;
        for (it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
            delete* it;
            *it = 0;
        }
        m_Cards.clear();
    }
    int GetTotal() const
    {
        if (m_Cards.empty())
            return 0;

        if (m_Cards[0]->getValue() == 0)
            return 0;

        int total = 0;
        vector<Card*>::const_iterator it;
        for (it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
            total += (*it)->getValue();
        }

        bool containsAce = false;
        for (it = m_Cards.begin(); it != m_Cards.end(); ++it)
        {
            if ((*it)->getValue() == Card::ACE)
            {
                containsAce = true;
            }
        }

        if (containsAce && total <= 11)
        {
            total += 10;
        }

        return total;
    }
    ~Hand()
    {
        Clear();
    }

};

class GenericPlayer : public Hand
{
private:
    string m_Name;
public:
    virtual bool IsHitting() const = 0;
    bool IsBoosted() const
    {
        if (GetTotal() > 21)
        {
            Bust();
        }
    }
    void Bust() const
    {
        cout << "You bust!" << endl;
    }
    virtual ~GenericPlayer()
    {
    }
};



int main()
{
    cout << "Task1" << endl;
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    
    
    cout << endl;
    cout << "Task2" << endl;

    Pair<int, double> p1_2(6, 7.8);
    cout << "Pair: " << p1_2.first() << ' ' << p1_2.second() << '\n';

    const Pair<double, int> p2_2(3.4, 5);
    cout << "Pair: " << p2_2.first() << ' ' << p2_2.second() << '\n';

    cout << endl;
    cout << "Task3" << endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}
