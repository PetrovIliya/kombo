#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;


struct PRNG
{
    unsigned seed = 0;
};

class Deck
{
public:

    Deck()
    {
        initGenerator();
        initDeckOfCards();
    }


    map <int, int> getDeckOfCards()
    {
        return deckOfCards;
    }

    void randomize()
    {
        initRandNumberForEachCard();
        for (int i = 1; i <= quantityOfCardsPerDeck; ++i)
        {
            int tmp = deckOfCards[i];
            deckOfCards[i] = deckOfCards[randNumberForEachCard[i]];
            deckOfCards[randNumberForEachCard[i]] = tmp;
        }
    }

    void showDeckWithMessage(string message)
    {
        // copy(deckOfCards.begin(), deckOfCards.end(), ostream_iterator<int>(cout, " ")); don't work with std::map, need int*, but its makes more probmlems then solves
        cout << message << endl;
        for (int i = 1; i <= quantityOfCardsPerDeck; ++i)
        {
            cout << deckOfCards[i] << " ";
        }
        cout << endl << endl;
    }

private:
    map <int, int> deckOfCards;
    map <int, int> randNumberForEachCard;
    int quantityOfCardsPerDeck = 36;
    PRNG generator;


    void initDeckOfCards()
    {
        for (int i = 1, j = quantityOfCardsPerDeck; i <= quantityOfCardsPerDeck; ++i, j--)
        {
            deckOfCards[i] = j;
        }
    }

    void initRandNumberForEachCard()
    {
        for (int i = 1; i <= quantityOfCardsPerDeck; ++i)
        {
            randNumberForEachCard[i] = random(1, quantityOfCardsPerDeck);
        }
    }

    void initGenerator()
    {
        generator.seed = unsigned(std::time(nullptr));
    }

    unsigned random( unsigned minValue, unsigned maxValue)
    {
        assert(minValue < maxValue);
        generator.seed = (generator.seed * 73129 + 95121);
        return (generator.seed % (maxValue + 1 - minValue)) + minValue;
    }

};

int main()
{
    Deck deck;

    deck.showDeckWithMessage("normal deck of cards is:");
    deck.randomize();
    deck.showDeckWithMessage("randomized deck of cards is:");
    deck.randomize();
    deck.showDeckWithMessage("and again:");

    return 0;
}

