#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <cassert>
#include "Random.h"

struct Card {
    enum Rank {
        rankAce,
        rank2,
        rank3,
        rank4,
        rank5,
        rank6,
        rank7,
        rank8,
        rank9,
        rank10,
        rankJack,
        rankQueen,
        rankKing,
        maxRanks
    };

    enum Suit {
        club,
        diamond,
        heart,
        spade,
        maxSuits
    };

    Rank rank{};
    Suit suit{};

    static constexpr std::array allRanks{ rankAce, rank2, rank3, rank4, rank5, rank6, rank7,
        rank8, rank9, rank10, rankJack, rankQueen, rankKing };
    static constexpr std::array allSuits{ club, diamond, heart, spade };

    friend std::ostream& operator<<(std::ostream& out, const Card &card) {
        static constexpr std::array<std::string_view, maxRanks> ranks{
            "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        static constexpr std::array<std::string_view, maxSuits> suits{ "C", "D", "H", "S" };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }
};

class Deck {
private:
    std::array<Card, 52> m_cards {};
    std::size_t m_nextCardIndex { 0 };

public:
    Deck() {
        std::size_t index{0};
        for (auto suit : Card::allSuits) {
            for (auto rank : Card::allRanks) {
                m_cards[index++] = Card{ rank, suit };
            }
        }
    }

    void shuffle() {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_nextCardIndex = 0;
    }
    Card dealCard() {
        assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_cards[m_nextCardIndex++];
    }

};

// To be continued later


int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}
