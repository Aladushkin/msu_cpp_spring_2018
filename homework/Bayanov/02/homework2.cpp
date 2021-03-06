#include <iostream>
#include <vector>

#include "numbers.dat"

const uint32_t MAX_VAL = 100001;

void SieveEratosthenes(std::vector<uint32_t>& min_prime_div,
                       std::vector<uint32_t>& primes) {
  for (uint32_t it = 2; it < MAX_VAL; ++it) {
    min_prime_div[it] = it;
  }
  min_prime_div[0] = 1;
  min_prime_div[1] = 0;
  for (uint32_t it = 2; it < MAX_VAL; ++it) {
    if (min_prime_div[it] == it) {
      primes.push_back(it);
    }
    for (uint32_t prime : primes) {
      if (prime * it < MAX_VAL and prime <= min_prime_div[it]) {
        min_prime_div[prime * it] = prime;
      } else {
        break;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  if (!(argc & 1) || argc == 1) return -1;

  std::vector<uint32_t> min_prime_div(MAX_VAL);
  std::vector<uint32_t> primes;

  SieveEratosthenes(min_prime_div, primes);

  for (uint32_t it = 1; it < argc; it += 2) {
    uint32_t left_bound = atoi(argv[it]);
    uint32_t right_bound = atoi(argv[it + 1]);

    bool left_is_here = false;
    bool right_is_here = false;

    uint32_t primes_counter = 0;

    for (size_t ind = 0; ind < Size; ++ind) {
      if (left_bound <= Data[ind] and Data[ind] <= right_bound) {
        primes_counter += (min_prime_div[Data[ind]] == Data[ind]);
      }
      left_is_here |= left_bound == Data[ind];
      right_is_here |= right_bound == Data[ind];
    }

    if (left_is_here && right_is_here) {
      std::cout << primes_counter << "\n";
    } else {
      std::cout << 0 << "\n";
    }
  }

  return 0;
}
