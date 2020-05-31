#pragma once

#include "Polynomial.hpp"

namespace lab {

class PolynomialRing {
public:
    PolynomialRing(const PolynomialRing& that) = default;

    explicit PolynomialRing(uint64_t p);

    [[nodiscard]] uint64_t getP() const;

    [[nodiscard]] Polynomial add(const Polynomial& left, const Polynomial& right) const;

    [[nodiscard]] Polynomial subtract(const Polynomial& left, const Polynomial& right) const;

    [[nodiscard]] Polynomial multiply(const Polynomial& left, const Polynomial& right) const;

    [[nodiscard]] Polynomial multiply(const Polynomial& polynomial, const uint64_t & num) const;

    [[nodiscard]] Polynomial multiply(const uint64_t & num, const Polynomial& polynomial) const;

private:
    uint64_t _p;
};

} // namespace lab

#include "PolynomialRing.hxx"