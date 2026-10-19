*This project has been created as part of the 42 curriculum by zhier, siooi.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks (`a` and `b`) and a small set of operations, printing the shortest sequence of operations it can find. The goal is to explore algorithmic complexity by implementing four strategies — simple, medium, complex and adaptive — and picking one at runtime.

**Operations**

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate up (top goes to bottom) `a` / `b` / both |
| `rra` / `rrb` / `rrr` | Rotate down (bottom goes to top) `a` / `b` / both |

## Instructions

```sh
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files
make fclean   # removes objects and binaries
make re       # rebuilds from scratch
```

**Flags** (optional, can be placed anywhere among the numbers)

| Flag | Strategy |
|------|----------|
| `--simple` | Insertion sort, O(n²) |
| `--medium` | Chunk sort, O(n√n) |
| `--complex` | Quick sort with two pivots, O(n log n) |
| `--adaptive` | Chooses based on disorder (default) |
| `--bench` | Prints disorder, strategy and operation counts to stderr |

### Examples

```sh
# Basic usage
./push_swap 2 1 3 6 5 8

# Numbers as a single string
./push_swap "4 67 3 87 23"

# Force a strategy and count operations
./push_swap --simple 5 4 3 2 1 | wc -l
./push_swap --complex 4 67 3 87 23 | wc -l

# Benchmark mode: hide the operations, show the metrics only
./push_swap --bench 4 67 3 87 23 > /dev/null

# Check the result with the checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Count operations for 100 / 500 random numbers
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l

# Check with the checker while saving the benchmark to a file
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)

# Feed operations to the checker by hand (Ctrl+D to finish)
./checker 3 2 1 0

# Error cases (prints "Error" on stderr)
./push_swap 0 one 2 3
./push_swap 3 2 3
```

## Algorithms

All strategies first replace each value with its rank (`index`, 0..n-1). Inputs of 5 or fewer elements use a hard-coded `fixed_sort`.

**Simple — Insertion sort, O(n²)**
Push two elements to `b`, then repeatedly push the *cheapest* element of `a` into its correct position in `b` (cost = rotations of `a` + rotations of `b`, shared via `rr`/`rrr`). Sort the last 3 in `a`, push everything back the same way, then rotate the minimum to the top. Each of the n pushes can cost up to O(n) rotations → O(n²).

**Medium — Chunk sort, O(n√n)**
Push elements from `a` to `b` in a sliding window of width `1.5·√n` over the ranks; smaller ones are rotated to the bottom of `b`, giving a rough "pyramid" in `b`. Then push back the cheapest element each time. Each element waits at most O(√n) rotations → O(n√n).

**Complex — Three-way quick sort, O(n log n)**
Split the remaining part of `a` with two pivots (35% and 65% of the ranks): the bottom third goes to the bottom of `b`, the middle third to the top of `b`, the top third stays in `a`. Repeat until 5 remain, `fixed_sort` them, then push back cheapest-first. Each pass removes a constant fraction of `a`, giving O(log n) passes of O(n) moves.

**Adaptive — based on disorder**
Disorder is the share of inverted pairs (0 = sorted, 1 = reversed), computed before any move.

| Disorder | Strategy | Why |
|----------|----------|-----|
| `< 0.2` | Simple | Nearly sorted: few elements are out of place, so cheapest-insertion moves very little. |
| `0.2 – 0.5` | Medium | Partly sorted: chunks keep most elements close to their target. |
| `≥ 0.5` | Complex | Very messy: partitioning scales best. |

Space usage is O(n) for every strategy (the two linked-list stacks).

## Resources

- [Push Swap Tutorial (Simple)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push Swap Tutorial (Medium)](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376)
- [Push Swap Tester](https://github.com/sisheng1998/push_swap_tester)
- [Push Swap Visualiser](https://github.com/Niimphu/push_swap_visualiser)
- [Detailed Explanation](https://github.com/sisheng1998/push_swap/tree/main/explanation)

**AI usage:** AI was used to help draft this README and to review explanations of the algorithms.

## Contributors

- **zhier** — Complex algorithm
- **siooi** — Input parsing, operations, simple / medium / adaptive algorithms, benchmark, checker
