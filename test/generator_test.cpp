#include "coro/generator.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(Generator, yield) {
  auto vec = karus::coro::Generator<int>::from(1, 2, 3, 4)
                 .for_each([](auto &x) { x *= 2; })
                 .collect<std::vector<int>>();

  std::cout << "vector\n";
  for (auto x : vec) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  std::vector<int> target{2, 4, 6, 8};
  ASSERT_EQ(vec, target);

  std::cout << "where x % 3 != 0\n";
  for (auto x : karus::coro::Generator<int>::from_iter(vec)
                    .where([](const auto &x) { return x % 3; })
                    .collect<std::vector<int>>()) {
    std::cout << x << ' ';
    ASSERT_TRUE(x % 3);
  }
  std::cout << '\n';
}
