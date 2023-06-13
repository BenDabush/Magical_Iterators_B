#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
TEST_CASE("isPrime") {

    SUBCASE("Prime numbers") {
        CHECK(ariel::isPrime(2));
        CHECK(ariel::isPrime(3));
        CHECK(ariel::isPrime(29));
        CHECK(ariel::isPrime(31));
    }

    SUBCASE("Non-prime numbers") {
        CHECK_FALSE(ariel::isPrime(-5));
        CHECK_FALSE(ariel::isPrime(0));
        CHECK_FALSE(ariel::isPrime(1));
        CHECK_FALSE(ariel::isPrime(21));
        CHECK_FALSE(ariel::isPrime(28));
    }
}


TEST_CASE("Adding and removing elements and check size") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);

    container.removeElement(2);
    container.removeElement(4);
    CHECK(container.size() == 3);
}

TEST_CASE("Comparing iterators") {
    MagicalContainer container;
    for (int i = 1; i <= 10; ++i) {
        container.addElement(i * 7);
    }

    SUBCASE("Comparing AscendingIterator with itself") {
        MagicalContainer::AscendingIterator itr1(container);
        MagicalContainer::AscendingIterator itr2(container);
        CHECK(itr1 == itr2);
        CHECK(!(itr1 != itr2));
        CHECK(!(itr1 < itr2));
        CHECK(!(itr1 > itr2));
    }

    SUBCASE("Comparing SideCrossIterator with itself") {
        MagicalContainer::SideCrossIterator itr1(container);
        MagicalContainer::SideCrossIterator itr2(container);
        CHECK(itr1 == itr2);
        CHECK(!(itr1 != itr2));
        CHECK(!(itr1 < itr2));
        CHECK(!(itr1 > itr2));
    }

    SUBCASE("Comparing PrimeIterator with itself") {
        MagicalContainer::PrimeIterator itr1(container);
        MagicalContainer::PrimeIterator itr2(container);
        CHECK(itr1 == itr2);
        CHECK(!(itr1 != itr2));
        CHECK(!(itr1 < itr2));
        CHECK(!(itr1 > itr2));
    }
}

TEST_CASE("AscendingIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::AscendingIterator ascIter(container);

    auto iter1 = ascIter.begin();
    auto iter2 = ascIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);

}

TEST_CASE("SideCrossIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::SideCrossIterator primeIter(container);

    auto iter1 = primeIter.begin();
    auto iter2 = primeIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
}

TEST_CASE("PrimeIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);

    auto iter1 = primeIter.begin();
    auto iter2 = primeIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
}