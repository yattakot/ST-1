// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// ============================================================================
// Тесты для checkPrime
// ============================================================================

TEST(PrimeTests, checkPrime_SmallPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
}

TEST(PrimeTests, checkPrime_SmallNonPrimes) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(100));
}

TEST(PrimeTests, checkPrime_LargePrime) {
    EXPECT_TRUE(checkPrime(999999937));
}

// ============================================================================
// Тесты для nPrime
// ============================================================================

TEST(PrimeTests, nPrime_FirstTen) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
    EXPECT_EQ(nPrime(10), 29);
}

TEST(PrimeTests, nPrime_LargerIndex) {
    EXPECT_EQ(nPrime(100), 541);
}

// ============================================================================
// Тесты для nextPrime
// ============================================================================

TEST(PrimeTests, nextPrime_BasicCases) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(14), 17);
}

TEST(PrimeTests, nextPrime_EvenAndOdd) {
    EXPECT_EQ(nextPrime(20), 23);
    EXPECT_EQ(nextPrime(21), 23);
    EXPECT_EQ(nextPrime(22), 23);
}

// ============================================================================
// Тесты для sumPrime
// ============================================================================

TEST(PrimeTests, sumPrime_EdgeCases) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
}

TEST(PrimeTests, sumPrime_SmallRange) {
    EXPECT_EQ(sumPrime(10), 17);

    EXPECT_EQ(sumPrime(20), 77);
}

TEST(PrimeTests, sumPrime_LargeRange) {
    uint64_t res = sumPrime(2000000);
    uint64_t expected = 142913828922;
    EXPECT_EQ(res, expected);
}

// ============================================================================
// Интеграционный тест: проверка согласованности функций
// ============================================================================

TEST(PrimeTests, Integration_nPrime_and_checkPrime) {
    for (uint64_t i = 1; i <= 50; ++i) {
        uint64_t prime = nPrime(i);
        EXPECT_TRUE(checkPrime(prime))
            << "nPrime(" << i << ") = " << prime << " is not prime!";
    }
}

TEST(PrimeTests, Integration_nextPrime_and_checkPrime) {
    for (uint64_t x : {1, 10, 50, 100, 500}) {
        uint64_t next = nextPrime(x);
        EXPECT_TRUE(checkPrime(next))
            << "nextPrime(" << x << ") = " << next << " is not prime!";
        EXPECT_GT(next, x) << "nextPrime(" << x << ") should be > " << x;
    }
}
