#include <iostream>
#include <cassert>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <set>

using namespace std;

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void deleteBack()
    {
        int* data = new int[m_length - 1];

        for (int before = 0; before < m_length - 1; ++before)
            data[before] = m_data[before];
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    void deleteFront()
    {
        int* data = new int[m_length - 1];

        for (int before = 1; before < m_length; ++before)
            data[before - 1] = m_data[before];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    void push_back(int value) { insertBefore(value, m_length); }
    void printArray()
    {
        for (int i = 0; i < m_length; ++i)
        {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }
    void sortArray()
    {
        sort(m_data, m_data + m_length);
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }
};

void printVector(vector<int>& vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

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

int main()
{
    {
        cout << "Task 1" << endl;
        ArrayInt arr(10);
        for (int i = 0; i < arr.getLength(); ++i)
        {
            arr[i] = getRandomNum(1, 10);
        }
        arr.printArray();
        arr.deleteBack();
        arr.printArray();
        arr.deleteFront();
        arr.printArray();
        arr.sortArray();
        arr.printArray();
    }
    cout << endl;
    {
        cout << "Task 2" << endl;
        vector<int> vec(5);
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i] = getRandomNum(1, 5);
        }
        printVector(vec);

        std::set <int> Set(vec.begin(), vec.end());
        cout << Set.size() << endl;		
    }


}
